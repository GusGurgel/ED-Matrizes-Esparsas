/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// SparseMatrix (Implementation file) 
// 
// Criação:     18 Out 2022
// Atualização: 18 Out 2022
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula: 539226
//
************************************************/

#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int r, int c){
	//Criação de matrix com valor nulo/negativo
	if(r < 1 || c < 1){
		throw std::invalid_argument("invalid matrix size");
	}
	
	row_s = r;
	col_s = c;
	
	//Criação do Node principal (0,0)
	head = new Node{ nullptr, nullptr, 0, 0, 0}; 
	//Nó auxiliar para criação dos sentinelas
	Node* current = head; 						 
	
	//cria os sentinelas na linha 0
	for(int i {1}; i < col_s+1; i++){
		current->right = new Node { nullptr, nullptr, 0, i, 0};
		current = current->right;
		//Current aponta para ele mesmo para manter a circularidade
		//das colunas vazias
		current->down = current;
		//o último sentinela aponta para head, para manter a circularidade
		if(i == col_s)
			current->right = head;
	}
	
	//reseta o o current
	current = head; 
	
	//cria os sentinelas na coluna 0
	for(int i {1}; i < row_s+1; i++){
		current->down = new Node { nullptr, nullptr, i, 0, 0};
		current = current->down;
		//Current aponta para ele mesmo para manter a circularidade
		//das linhas
		current->right = current;
		//o último sentinela aponta para head, para manter a circularidade
		if(i == row_s)
			current->down = head;
	}
}

void SparseMatrix::insert(int r, int c, double value){
	//Índice fora do range da matriz
	if(r > row_s || r < 1 || c > col_s || c < 1){
		throw std::out_of_range("matrix index out of range");
	}
	//*******************************
	// CONTEXTO DE ADIÇÃO NA COLUNA
	//*******************************
	//Aponta para o elemento que vem antes do qual se quer adicionar
	Node* back  = nullptr;	
	//Aponta para o elemento que vem depois do qual se quer adicionar
	Node* front = nullptr;
	//Aponta para o sentinela
	Node* sent  = head;
	//Anda até o sentinela de coluna desejado
	while(sent->col != c){
		sent = sent->right;
	}
	//back referencia o sentinela
	back = sent;
	//Acha o back
	while(back->down != sent && back->down->row < r){
		back = back->down;
	}
	//front é o elemento que está a frente de back, seja ele o próprio
	//sentinela, ou outro nó.
	front = back->down;
	
	//Já existe um elemento na quela (linha,coluna) expecífica
	if(back->down->row == r){
		//Se você ta tentando colocar um valor diferente de
		//zero, então é so mudar o valor
		if(value != 0){
			back->down->value = value;
			return;
		}
	}else{
		//Se não tem elemento lá você está tentando colocar
		//zero, então é só deixar como está
		if(value == 0)
			return;
	}
	if(value != 0){
		//O elemento é adicionado abaixo do back e antes do front
		back->down = new Node { nullptr, front, r, c, value};
	}
	//**********************************
	// FIM CONTEXTO DE ADIÇÃO NA COLUNA
	//**********************************
	
	//*****************************
	// CONTEXTO DE ADIÇÃO NA LINHA
	//*****************************
	//Salva uma referência do nó alocado
	Node* ref = back->down;
	//Remove a referência caso o valor seja nulo
	if(value == 0)
		back->down = front->down;
	//reseta o sentinela usado anteriormente
	sent = head;
	//Anda até o sentinela de linha desejado
	while(sent->row != r){
		sent = sent->down;
	}
	//back referencia o sentinela
	back = sent;
	//pega o back
	while(back->right != sent && back->right->col < c){
		back = back->right;
	}
	//Agora o front é que está a direita do back, seja ele um outro
	//elemento, ou até mesmo um sentinela
	front = back->right;
	if(value == 0){
		back->right = front->right;
		delete ref;
		return;
	}
	//O elemento é adicionado a direita do back 
	//e a esquerda do front
	back->right = ref;
	ref->right  = front;
}

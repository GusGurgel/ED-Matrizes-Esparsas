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
		throw std::out_of_range("index out of the matrix range");
	}
	//*****************************
	//CONTEXTO DE ADIÇÃO NA COLUNA
	//*****************************
	//Aponta para o elemento que vem antes do qual a que adicionar
	Node* back  = nullptr;	
	//Aponta para o elemento que vem depois do qual a que adicionar
	Node* front = nullptr;
	//Aponta para o sentinela
	Node* sent  = head;
	//Anda até a coluna que se deseja adicionar
	while(sent->col != c){
		sent = sent->right;
	}
	//back vai para o sentinela
	back = sent;
	//pega o back
	while(back->down != sent && back->down->row <= r){
		back = back->down;
	}
	//~ std::cout << back->down->row << std::endl;
	
	//Existe um elemento na quela (linha,coluna) expecífica
	if(back->down->row == r){
		back->down->value = value;
		return;
	}
	//Meu front é o elemento a frente do meu back
	//caso ele não seja um sentinela
	if(back->down != sent){
		front = back->down;
	}
	back->down = new Node { nullptr, front, r, c, value};
	//**********************************
	//FIM CONTEXTO DE ADIÇÃO NA COLUNA
	//**********************************
}

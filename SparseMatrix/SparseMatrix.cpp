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
	
	head = new Node{ nullptr, nullptr, 0, 0, 0}; //Criação do Node principal (0,0)
	Node* current = head; 						 //Nó auxiliar para criação dos sentinelas
	
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

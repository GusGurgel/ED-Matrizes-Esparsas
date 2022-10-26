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
	row_s = r;
	col_s = c;
	head = new Node{ nullptr, nullptr, 0, 0, 0}; //Criação do Node principal
	Node* current = head; 						 //Nó auxiliar para criação dos sentinelas
	
	//cria os sentinelas na linha 0
	for(int i {1}; i < col_s+1; i++){
		current->right = new Node { nullptr, nullptr, 0, i, 0};
		current = current->right;
	}
	current = head; //reseta o o current
	//cria os sentinelas na coluna 0
	for(int i {1}; i < row_s+1; i++){
		current->down = new Node { nullptr, nullptr, i, 0, 0};
		current = current->down;
	}
}

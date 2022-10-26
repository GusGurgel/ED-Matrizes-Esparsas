/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// main 
// 
// Criação:     24 Out 2022
// Atualização: 24 Out 2022
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula: 539226
//
************************************************/
#define SIZE 1

#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main(){
	SparseMatrix sm(SIZE,SIZE);
	cout << "(HEAD)" << sm.head << "(linha:" << sm.head->row << ")" << "(coluna:" << sm.head->col << ")" << endl;
	Node* current = sm.head;
	//Passando pela linha  0 
	for(int i = 1; i < SIZE+1; i++){
		cout << current->right << "(linha:" << current->right->row << ")" << "(coluna:" << current->right->col << ")" << endl;
		current = current->right;
	}
	current = sm.head;
	//Passando pela coluna 0
	for(int i = 1; i < SIZE+1; i++){
		cout << current->down << "(linha:" << current->down->row << ")" << "(coluna:" << current->down->col << ")" << endl;
		current = current->down;
	}
}

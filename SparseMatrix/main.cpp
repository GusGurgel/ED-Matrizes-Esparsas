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

#include <iostream>
#include "SparseMatrix.h"

#define row_size 4
#define col_size 4

using namespace std;

void validate(double expected[row_size][col_size], const SparseMatrix&);

int main(){
	int n{1};
	SparseMatrix sm(row_size,col_size);
	double expected[row_size][col_size]{0};
	
	for(int i = 0; i < row_size; i++){
		for(int y = 0; y < col_size; y++){
			expected[i][y] = n;
			sm.insert(i+1,y+1,n);
			n++;
		}
	}
	sm.insert(1,1,0);
	validate(expected, sm);
}

void validate(double expected[row_size][col_size], const SparseMatrix& sm){
	Node* current = sm.head->down->right;
	for(int i = 0; i < row_size; i++){
		for(int y = 0; y < col_size; y++){
			if(current->value != expected[i][y]){
				cout << "Validate failed" << endl;
				cout << "expected value = " << expected[i][y] << endl;
				cout << "current  value = " << current->value << endl;
				exit(EXIT_FAILURE);
			}
			current = current->right;
		}
		current = current->right->down;
	}
	cout << "Validate success" << endl;
	exit(EXIT_SUCCESS);
}


/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// teste de validação do método insert 
//
// !!!!!!!!!!!!LEIA!!!!!!!!!!!!!
// Caso queira usar esse script
// você tera que alterar head
// para público, pois a main
// tem que ter o acesso a ele
// para poder efetuar os testes
// !!!!!!!!!!!!LEIA!!!!!!!!!!!!!
// 
// Criação:     28 Out 2022
// Atualização: 28 Out 2022
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
	int n{0}; //Contador
	//Matriz Esparsa
	SparseMatrix sm(row_size,col_size);
	//Matriz Esperada
	double expected[row_size][col_size]{0};
	
	//Insere valores de forma cresente na matriz esperada
	for(int i = 0; i < row_size; i++){
		for(int y = 0; y < col_size; y++){
			expected[i][y] = ++n;
		}
	}
	//*******************************
	//   manipulação com insert
	//*******************************	
	//linha 1
	sm.insert(1,3,3);
	sm.insert(1,4,4);
	sm.insert(1,1,1);
	sm.insert(1,2,2);
	sm.insert(1,1,0);
	sm.insert(1,1,1);
	//linha 2
	sm.insert(2,1,5);
	sm.insert(2,2,6);
	sm.insert(2,2,7);
	sm.insert(2,2,6);
	sm.insert(2,3,7);
	sm.insert(2,4,8);
	//linha 3
	sm.insert(3,1,9);
	sm.insert(3,2,10);
	sm.insert(3,3,11);
	sm.insert(3,4,12);
	sm.insert(3,4,0);
	sm.insert(3,4,12);
	//linha 4
	sm.insert(4,1,13);
	sm.insert(4,2,14);
	sm.insert(4,3,15);
	sm.insert(4,3,0);
	sm.insert(4,3,50);
	sm.insert(4,3,15);
	sm.insert(4,4,16);
	
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


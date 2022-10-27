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

using namespace std;

int main(){
	SparseMatrix sm(2,2);
	sm.insert(1,1,1);
	cout << sm.head->right->down->value << endl;
	sm.insert(1,1,0);
	cout << sm.head->right->down->value << endl;
	sm.insert(1,1,22);
	cout << sm.head->right->down->value << endl;
	sm.insert(1,2,54);
	cout << sm.head->right->right->down->value << endl;
	cout << sm.head->right->down->value << endl;
	sm.insert(1,2,0);
	cout << sm.head->right->right->down->value << endl;
	sm.insert(1,2,0);
	cout << sm.head->right->right->down->value << endl;
}

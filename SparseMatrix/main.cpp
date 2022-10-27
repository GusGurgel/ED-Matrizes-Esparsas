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
	sm.insert(2,2,25.4);
	cout << sm.head->right->right->down->value << endl; 
	sm.insert(1,2,20.3);
	cout << sm.head->right->right->down->value << endl; 
}

/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// SparseMatrix (main file)
// 
// Criação:     18 Out 2022
// Atualização: 28 Out 2022
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula [UFC]: 539226
//
************************************************/

#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main(){
	SparseMatrix* sm = new SparseMatrix(1,1);
	sm->insert(1,1,22);
	cout << sm->get(1,1) << " ";
	
	delete sm;
}


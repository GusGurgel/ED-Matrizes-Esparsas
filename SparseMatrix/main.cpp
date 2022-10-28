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
	SparseMatrix* sm = new SparseMatrix(3,3);
	sm->insert(1,1,1);
	sm->insert(1,2,1);
	sm->insert(1,3,1);
	
	sm->print();
	
	sm->insert(3,3,22);
	
	sm->print();
	
	sm->insert(2,3,234);
	sm->print();
	
	delete sm;
}


/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// estrutura-construtor.cpp
//
//  Arquivo referente ao teste de estrutura 
// 	do construtor base da matriz esparsa
// 
// !!!!!!!!!!!!LEIA!!!!!!!!!!!!!
// Caso queira usar esse script
// você tera que alterar head
// para público, pois a main
// tem que ter o acesso a ele
// para poder efetuar os testes
//!!!!!!!!!!!!LEIA!!!!!!!!!!!!!
//
// Criação:     27 Out 2022
// Atualização: 27 Out 2022
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula: 539226
//
************************************************/
//Macro referente ao tamanho da matriz a ser testada
#define SIZE 3

#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main(){
	//Alocação estática da matriz
	SparseMatrix sm(SIZE,SIZE);
	cout << "(HEAD)Address:" << sm.head << "(linha:" << sm.head->row << ")" << "(coluna:" << sm.head->col << ")" << endl << endl;
	Node* current = sm.head->right;
	//Passando pela linha  0 
	for(int i = 1; i < SIZE+1; i++){
		cout << "Address:"<< current << " (linha:" << current->row << ")" << "(coluna:" << current->col << ")" << endl;
		if(current->down == current)
			cout << "{down column circularity ok}" << endl;
		if(i == SIZE && current->right == sm.head){
			cout << "{last right column circularity ok}" << endl;
		}
		cout << endl;
		current = current->right;
	}
	current = sm.head->down;
	//Passando pela coluna 0
	for(int i = 1; i < SIZE+1; i++){
		cout << current << "(linha:" << current->row << ")" << "(coluna:" << current->col << ")" << endl;
		if(current->right == current)
			cout << "{rigth line circularity ok}" << endl;
		if(i == SIZE && current->down == sm.head)
			cout << "{last down line circularity ok}" << endl;
		cout << endl;
		current = current->down;
	}
}

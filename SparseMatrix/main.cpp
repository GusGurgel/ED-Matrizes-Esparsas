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
#include <fstream>
#include "SparseMatrix.h"

using namespace std;

//********************************************
//   { Ler (de um arquivo) Matriz Esparsa }
//	
// Essa função utiliza um arquivo de texto
// como base para criar um matriz esparsa
//
//	file_name = "Nome do arquivo"
//
//*********************************************

SparseMatrix* readSparseMatrix (string file_name);

int main(){
	int files_cont {0};
	string file_name;
	cin >> files_cont;
	
	for(int i {1}; i <= files_cont; i++){
		cin >> file_name;
		SparseMatrix* sm = readSparseMatrix(file_name);
		sm->print();
		delete sm;
	}
}

SparseMatrix* readSparseMatrix (string file_name){
	int row_size, col_size; //Tamanho da matriz
	int r, c;				//Coordenadas de inserção
	double value;			//Valor de inserção
	
	SparseMatrix* ret; 		//Matriz que irá ser retornada
	ifstream read; 	  		//Stream de leitura

	//Abrindo o arquivo que irá ser lido
	read.open(file_name);
	if(!read.is_open()){
		//Não foi possivel abrir o arquivo
		cout << "fail trying to open \"" << file_name << "\"" << endl;
		exit(EXIT_FAILURE);
	}
	//Pegando dimensões da matriz
	read >> row_size >> col_size;
	//Aloca a matriz
	ret = new SparseMatrix(row_size, col_size);
	//Insere todos os valores
	while(read >> r >> c >> value)
		ret->insert(r, c, value);
	//Fecha o arquivo depois de ler
	read.close();
	return ret;
}

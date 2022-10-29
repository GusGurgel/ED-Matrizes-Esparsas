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
//********************************************
SparseMatrix* readSparseMatrix (string file_name);

//*********************************
//     { Soma Matrizes Esparsas }
//	
//	Soma duas matrizes e retorna
//  o resultado em uma matriz nova
//
//*********************************
SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B);

//**************************************
//  { Multiplica Matrizes Esparsas }
//	
//	multiplica duas matrizes e retorna
//  o resultado em uma matriz nova
//
//**************************************
SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B);

int main(){
	SparseMatrix* sm1 = readSparseMatrix("m1.txt");
	SparseMatrix* sm2 = readSparseMatrix("m2.txt");
	SparseMatrix* sm_mult = multiply(sm1,sm2);
	
	sm_mult->print();

	delete sm1;
	delete sm2;
	delete sm_mult;
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
		return nullptr;
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

SparseMatrix* sum(SparseMatrix* A, SparseMatrix* B){
	int row_s = A->rowSize(); //Quantidade de linhas da matriz de retorno
	int col_s = A->colSize(); //Quantidade de colunas da matriz de retorno
	
	if(row_s != B->rowSize() || col_s != B->colSize()){
		//A soma de matrizes não é possível
		cout << "fail trying to sum matrices" << endl;
		return nullptr;
	}
	
	//Aloca matriz de retorno
	SparseMatrix* ret = new SparseMatrix(row_s, col_s);
	
	//Insere a soma das duas matrizes na matriz de retorno
	for(int i {1};i <= row_s ; i++){
		for(int j {1}; j <= col_s; j++){
			ret->insert(i, j, (A->get(i,j) + B->get(i,j)));
		}
	}
	
	return ret;
}

SparseMatrix* multiply(SparseMatrix* A, SparseMatrix* B){
	int row_s = A->rowSize(); //Quantidade de linhas da matriz de retorno
	int col_s = B->colSize(); //Quantidade de colunas da matriz de retorno

	if(A->colSize() != B->rowSize()){
		//A soma de matrizes não é possível
		cout << "fail trying to multiply matrices" << endl;
		return nullptr;
	}
	
	//Aloca matriz de retorno
	SparseMatrix* ret = new SparseMatrix(row_s, col_s);
	
	//Insere a multiplicação das duas matrizes na matriz de retorno
	for(int i {1}; i <= row_s; i++){
		for(int j {1}; j <= col_s; j++){
			for(int k {1}; k <= A->colSize(); k++){
				ret->insert(i, j, ret->get(i,j) + (A->get(i,k) * B->get(k,j)));
			}
		}
	}
	
	return ret;
}

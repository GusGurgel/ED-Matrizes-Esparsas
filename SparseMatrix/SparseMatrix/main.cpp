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
#include <vector>
#include <limits>
#include <sstream>
#include "SparseMatrix.h"

#define DEFAULT_LINE_SIZE 40

using namespace std;

//********************************************
//   { Ler (de um arquivo) Matriz Esparsa }
//	
//  Essa função utiliza um arquivo de texto
//  como base para criar um matriz esparsa
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

//**************************************
//         { Pegar Menu }
//
//  Lê o arquivo e retorna o arquivo
//  menu.txt (caso ele exista)
//
//**************************************
string getMenu();

//**************************************
//         { Criar linha }
//
//  faz uma linha com tamanho (size) 
//  passado usando o caractére c
//
//**************************************
void makeLine(int size, char c = '=');

int main(){
	vector<SparseMatrix*> Matrixs;	//Vetor com as matrizes alocadas
	string commandLine; 			//Linha do comando passado
	string command; 				//Comando passado
	bool firstCommand = true;		//Diz se é o primeiro comando
	
	cout << getMenu();
	
	while(true){
		stringstream commandStream; //Stream de comando
		//Sé for o primeiro comando printa uma linha
		if(firstCommand) makeLine(DEFAULT_LINE_SIZE);
		//Pega o comando do console
		getline(cin, commandLine);
		commandStream << commandLine;
		commandStream >> command;
	
		if(command == "create"){
			int row_s, col_s; //Tamanho da matriz
			commandStream >> row_s >> col_s;
			try{
				SparseMatrix* to_push = new SparseMatrix(row_s, col_s);
				Matrixs.push_back(to_push);
			}
			//Valor de matriz negativo ou muito grande
			catch(invalid_argument){
				cout << "invalid matrix size" << endl;
				continue;
			}
			cout << "SparseMatrix created whit:" << endl;
			cout << "Index:\t" << Matrixs.size()-1 << endl;
			cout << "Size :\t" << row_s << "X" << col_s << endl;
		}else if(command == "create_by_sum"){
			int index1, index2;
			commandStream >> index1 >> index2;
			try{
				SparseMatrix* to_push = sum(Matrixs.at(index1), Matrixs.at(index2));
				Matrixs.push_back(to_push);
			}
			//Tentando acessar um índice que ainda não existe
			catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
			catch(invalid_argument){
				cout << "incompatible sizes of matrices" << endl;
			}
		}else if(command == "create_by_mult"){
			int index1, index2;
			commandStream >> index1 >> index2;
			try{
				SparseMatrix* to_push = multiply(Matrixs.at(index1), Matrixs.at(index2));
				Matrixs.push_back(to_push);
			}
			//Tentando acessar um índice que ainda não existe
			catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
			catch(invalid_argument){
				cout << "incompatible sizes of matrices" << endl;
			}
		}else if(command == "create_by_read"){
			string filename;
			commandStream >> filename;
			try{
				SparseMatrix* to_push = readSparseMatrix(filename);
				Matrixs.push_back(to_push);
			}catch(invalid_argument){
				cout << "fail trying to open \"" << filename << "\"" << endl;
			}
		}else if(command == "delete"){
			int index;
			commandStream >> index;
			//Infelizmente a função erase não joga exeções em caso de out_of_range
			if(index+1 <= Matrixs.size()){
				delete Matrixs.at(index);
				Matrixs.erase(Matrixs.begin()+index);
			}else{
				cout << "index out of SparseMatrix vector" << endl;
			}
		}else if(command == "insert"){
			int index, row, col;
			double value;
			commandStream >> index >> row >> col >> value;
			try{
				Matrixs.at(index)->insert(row, col, value);
			}catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
		}else if(command == "printAll"){
			for(int i = {0}; i < Matrixs.size(); i++){
				cout << endl << "Index: " << i << endl;
				Matrixs[i]->print();
			}
		}else if(command == "print"){
			int index;
			commandStream >> index;
			//Índice fora da matriz
			try{
				Matrixs.at(index)->print();
			}catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
		}else if(command == "sum"){
			int index1, index2;
			commandStream >> index1 >> index2;
			try{
				SparseMatrix* result = sum(Matrixs.at(index1), Matrixs.at(index2));
				result->print();
				//Não mostre quantos nós foram deletados
				result->setShowDeleteNode(false);
				delete result;
			}
			//Tentando acessar um índice que ainda não existe
			catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
		}else if(command == "mult"){
			int index1, index2;
			commandStream >> index1 >> index2;
			try{
				SparseMatrix* result = multiply(Matrixs.at(index1), Matrixs.at(index2));
				result->print();
				//Não mostre quantos nós foram deletados
				result->setShowDeleteNode(false);
				delete result;
			}
			//Tentando acessar um índice que ainda não existe
			catch(out_of_range){
				cout << "index out of SparseMatrix vector" << endl;
			}
		}else if(command == "exit"){
			cout << "exiting..." << endl;
			for(SparseMatrix* pointer : Matrixs){
				delete pointer;
			}
			Matrixs.clear();
			makeLine(DEFAULT_LINE_SIZE);
			break;
		}
		else{
			cout << "command does not exist" << endl;
		}
		
		makeLine(DEFAULT_LINE_SIZE);
		firstCommand = false;
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
		throw invalid_argument("fail trying to open \"" + file_name + "\"");
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
		throw invalid_argument("incompatible sizes of matrices");
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
		throw invalid_argument("incompatible sizes of matrices");
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

string getMenu(){
	ifstream in_stream; //Buffer de leitura
	string ret = "";	//String de retorno
	in_stream.open("menu.txt");
	if(in_stream.is_open()){
		string read;
		//Remove linha inicial
		getline(in_stream,read);
		while(getline(in_stream, read)){
			ret += read + "\n";
		}
		ret += "\n";
		//fecha o arquivo
		in_stream.close();
	}
	return ret;
}

void makeLine(int size, char c){
	for(int i {0}; i < size; i++) cout << c;
	cout << endl;
}

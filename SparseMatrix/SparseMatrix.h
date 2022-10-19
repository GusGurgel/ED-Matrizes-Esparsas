/**************************************************
//
// Avaliação Parcial 2 - Estrutura de Dados UFC
//
// SparseMatrix (Header file) 
// 
// Criação:     18 Out 2022
// Atualização: 18 Out 2022
//
// Criado Por:
// Nome: Gustavo Gurgel Medeiros
// Número de Matrícula: 539226
//
************************************************/

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

/*===========================================
 *=  Struct que representa um nó da matriz	=
 *===========================================*/
struct Node {
	Node* right; 	//Ponteiro para o elemento da direita
	Node* left;		//Ponteiro para o elemento da esquerda
	
	int row;		//Índice de linha
	int column;		//Índice de coluna
	
	double valor;	//Valor que o nó contém
}

/*==========================================
 *=    Declaracao da classe SparceMatrix   =
 *==========================================*/
class SparseMatrix {
private:
	//Ponteiro que aponta para o elemento inicial 
	//Row: 0 / Colunm: 0
	Node* head = nullptr;
	
	int row_s;	//Número de linhas da matriz
	int col_s;	//Número de colunas da matriz
public:
	//******************************
	//   { Construtor da classe }
	//
	// r = "Número de linhas"
	// c = "Número de colunas"
	//
	// !Valida os valores passados!
	//******************************
	SparseMatrix(int r, int c);
};

#endif

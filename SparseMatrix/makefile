out: main.o SparseMatrix.o 
	g++ -o out main.o SparseMatrix.o
main.o: main.cpp
	g++ -c main.cpp
SparseMatrix.o: SparseMatrix.cpp SparseMatrix.h
	g++ -c SparseMatrix.cpp

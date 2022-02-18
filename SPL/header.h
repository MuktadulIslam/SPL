#include<bits/stdc++.h>
using namespace std;

int * input_matrix_from_file(char *fileName, int *row, int *column);
int * input_matrix_from_console(int *row, int *column);
void printMatrix(int *matrix, int row, int column);

int matrix_determinant(int *matrix, int row, int column);
void subMatrix(int *matrix, int *newMatrix, int row, int removeRow, int removeColumn);

int * matrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_multiplication_with_constant(int constant, int *matrix, int row, int column);


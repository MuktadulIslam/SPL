#include<bits/stdc++.h>
using namespace std;

void input_equation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);

int * input_normal_matrix_from_file(char *fileName, int *row, int *column);
int * input_normal_matrix_from_console(int *row, int *column);
void print_normal_matrix(int *matrix, int row, int column);

int normal_matrix_determinant(int *matrix, int row, int column);
void sub_normal_matrix(int *matrix, int *newMatrix, int row, int removeRow, int removeColumn);

int * normal_matrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * normal_matrix_subtraction(int *matrix1, int row1, int colmatrix_subtractionumn1, int *matrix2, int row2, int column2);
int * normal_matrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * normal_matrix_multiplication_with_constant(int constant, int *matrix, int row, int column);

int * normal_matrix_transpose(int *matrix, int row, int column);

int * normal_matrix_adjoint(int *matrix, int row, int column);
int * normal_matrix_inverse(int *matrix, int row, int column);






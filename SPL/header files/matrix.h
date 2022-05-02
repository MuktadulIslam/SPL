#include<bits/stdc++.h>
using namespace std;

int * input_matrix_from_file(char *fileName, int *row, int *column);
int * input_matrix_from_console(int *row, int *column);
int * matrix_memory_optimization(int * matrix, int row, int column);
void print_matrix(int *matrix, int row, int column);

int * matrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * matrix_multiplication_with_constant(int constant, int *matrix, int row, int column);

void matrix_determinant(int *matrix, int row, int column, int *value);
int matrix_determinant(int *matrix, int row, int column);
void subMatrix(int *matrix, int *newMatrix, int row, int removeRow, int removeColumn);

int * matrix_transpose(int *matrix, int row, int column);
int * matrix_adjoint(int *matrix, int row, int column);
int * matrix_inverse(int *matrix, int row, int column);


int lcm(int x, int y);
long long lcm(long long x, long long y);
int gcd(int x, int y);
long long gcd(long long x, long long y);
char * getNumber(char *p, char sign, int *matrix);
bool is_fractional_matrix(int *matrix);

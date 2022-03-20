#include<bits/stdc++.h>
using namespace std;

void input_fequation_from_console(int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);
void input_fequation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);

int * input_fmatrix_from_file(char *fileName, int *row, int *column);
int * input_fmatrix_from_console(int *row, int *column);
void print_fmatrix(int *matrix, int row, int column);

int * fmatrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);
int * fmatrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2);

void fmatrix_determinant(int *matrix, int row, int column, int *value);


int lcm(int x, int y);
int gcd(int x, int y);
char * getNumber(char *p, char sign, int *matrix);

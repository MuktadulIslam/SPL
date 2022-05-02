#include<bits/stdc++.h>
#define EPSILON 1e-9

using namespace std;

void input_equation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);

void write_introduction_part(string title, string equationFileName, string solutionFileName, int *coefficientMatrix, int row, int column, int *dMat, char *variables);
int rowElementSmaller(int *coefficientMatrix, int row, int column, int dMat[], int rowNo);
void makeLowerTriangleMatrix(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[]);
int max_length_of_number(int *matrix, int row, int column);

void solution_by_cramersRules(char *equationFileName, char *solutionFileName);
void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName);
void solution_by_GaussianElimination(char *equationFileName, char *solutionFileName);
void solution_by_GaussJordanMethod(char *equationFileName, char *solutionFileName);

void gauss_jacobi_iteration_method(char *equationFileName);
void gauss_seidel_iteration_method(char *equationFileName);


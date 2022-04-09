#include<bits/stdc++.h>
using namespace std;

void input_fequation_from_console(int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);
void input_fequation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat);

void solution_by_cramersRules(char *equationFileName, char *solutionFileName);
void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName);

#include<bits/stdc++.h>
using namespace std;

void write_introduction_part(string title, string equationFileName, string solutionFileName, int *coefficientMatrix, int row, int column, int *dMat, char *variables);
int max_length_of_number(int *matrix, int row, int column);

void solution_by_cramersRules(char *equationFileName, char *solutionFileName);
void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName);

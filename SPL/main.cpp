#include<bits/stdc++.h>
#include "matrix.h"
#include "fmatrix.h"

using namespace std;

int main(void) {
    /*int row, column, *matrix, *dMat;
    char *variables;
    int *m, r,c;
    input_equation_from_file("equation.txt", &row, &column, &matrix, &dMat, &variables);

    print_matrix(matrix, row, column);
    print_matrix(dMat, row, 1);*/
    //m = input_fmatrix_from_console(&r, &c);
    //print_fmatrix(m, r, c);

    //matrix = fmatrix_addition(matrix, row, column, m, r, c);
    //print_fmatrix(matrix, row, column);

    /*for(int i=1 ; i<126 ; i++)
        printf("%c----%d\n",i);*/
    solution_by_cramersRules("equation.txt" , "solution.txt");

    /*cout << " _       _" << endl;
    for(int i = 0 ; i<4 ; i++)
        cout << "|         |" << endl;
    cout << "|_       _|" << endl;*/
}


#include<bits/stdc++.h>
#include "n-header.h"
#include "f-header.h"

using namespace std;

int main(void) {
    int row, column, *matrix, *dMat;
    char *variables;
    input_equation_from_console(&row, &column, &matrix, &dMat, &variables);

    print_fmatrix(matrix, row, column);
    print_fmatrix(dMat, row, 1);
    //cout << endl << *matrix;
    //cout<< endl << "Bindu";
    cout << endl << *variables << *(variables+1) << *(variables+2);
}


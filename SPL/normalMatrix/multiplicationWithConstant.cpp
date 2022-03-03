#include<bits/stdc++.h>
#include "matrix.h"

using namespace std;

int * matrix_multiplication_with_constant(int constant, int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Multiplication with constant can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *mat, *temp;
        mat = (int*) malloc(row * column * sizeof(int));
        temp = mat;

        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                *mat = *(matrix + i*column + j) * constant;
                mat++;
            }
        }
        return temp;
    }
}

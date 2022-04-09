#include<bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * normal_matrix_transpose(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Transpose can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *mat, *temp;
        mat = (int*) malloc(row * column * sizeof(int));
        temp = mat;

        for(i=0 ; i<column ; i++) {
            for(j=0 ; j<row; j++) {
                *mat = *(matrix + j*column + i);
                mat++;
            }
        }
        return temp;
    }
}

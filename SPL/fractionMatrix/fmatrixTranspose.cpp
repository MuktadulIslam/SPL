#include<bits/stdc++.h>
#include "fmatrix.h"

using namespace std;

int * fmatrix_transpose(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Transpose can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *mat, *temp;
        mat = (int*) malloc(row * column * sizeof(int) * 2);
        temp = mat;

        for(i=0 ; i<column ; i++) {
            for(j=0 ; j<row; j++) {
                *mat = *(matrix + j*column*2 + i*2);
                mat++;
                *mat = *(matrix + j*column*2 + i*2 + 1);
                mat++;
            }
        }
        return temp;
    }
}

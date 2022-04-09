#include<bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * normal_matrix_adjoint(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Adjoint can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "Matrix Adjoint can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j, sign, m[row-1][column-1];
        int *mat, *temp;
        mat = (int*) malloc(row * column * sizeof(int));
        temp = mat;

        for(i=0 ; i<row ; i++) {
            if(i%2 == 0)
                sign = 1;
            else
                sign = -1;

            for(j=0 ; j<column ; j++) {
                sub_normal_matrix(matrix, &m[0][0], row, i, j);
                *mat++ = sign * normal_matrix_determinant(&m[0][0] , row-1, column-1);
                sign = -sign;
            }
        }
        return temp;
    }
}

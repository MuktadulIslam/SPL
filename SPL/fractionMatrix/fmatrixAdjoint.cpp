#include<bits/stdc++.h>
#include "fmatrix.h"

using namespace std;

int * fmatrix_adjoint(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "fMatrix Adjoint can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "fMatrix Adjoint can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j, sign, m[row-1][(column-1)*2], *p, det[2];
        int mat[row][column*2];
        p = det;

        for(i=0 ; i<row ; i++) {
            if(i%2 == 0)
                sign = 1;
            else
                sign = -1;

            for(j=0 ; j<column ; j++) {
                subfMatrix(matrix, &m[0][0], row, i, j);
                fmatrix_determinant(&m[0][0] , row-1, column-1, p);

                mat[i][j*2] = (*p) * sign;
                sign = -sign;
                mat[i][j*2 + 1] = *(p+1);
            }
        }
        return fmatrix_transpose(&mat[0][0], row, column);
    }
}

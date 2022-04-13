#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * matrix_adjoint(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "fMatrix Adjoint can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "fMatrix Adjoint can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        if(*matrix == INT_MAX) {
            matrix++;
            int i, j, sign, *p, det[2];
            p = det;

            int *mat, *temp, m[row-1+1][(column-1)*2];
            mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
            temp = mat;

                *mat++ = INT_MAX;       // intializing x[0][column] = INT_MAX to recognize as fmatrix
                m[0][(column-1)*2-1] = INT_MAX;

            for(i=0 ; i<row ; i++) {
                if(i%2 == 0)
                    sign = 1;
                else
                    sign = -1;

                for(j=0 ; j<column ; j++) {
                    subMatrix(matrix, &m[1][0], row, i, j);
                    matrix_determinant(&m[0][(column-1)*2-1] , row-1, column-1, p);

                    *mat++ = (*p) * sign;
                    sign = -sign;
                    *mat++ = *(p+1);
                }
            }
            return matrix_memory_optimization(temp, row, column);
        }

        else {
            return normal_matrix_adjoint(matrix, row, column);
        }
    }
}

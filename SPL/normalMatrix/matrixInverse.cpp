#include<bits/stdc++.h>
#include "matrix.h"

using namespace std;

int * matrix_inverse(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j , det, *mat;

        mat = matrix_adjoint(matrix, row, column);
        det = matrix_determinant(matrix, row, column);

        for(i=0 ; i<row ; i++)
            for(j=0 ; j<column ; j++)
                *(mat + i*column + j) = *(mat + i*column + j) / det;
        return mat;
    }
}

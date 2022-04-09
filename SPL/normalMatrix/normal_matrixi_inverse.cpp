#include<bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * normal_matrix_inverse(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j , det, *mat, *temp;

        det = normal_matrix_determinant(matrix, row, column);
        if(det == 0) {
            cout << "Matrix Inverse by Adj can't possible!!!!!!  Because matrix determinant is zero!!!" <<endl;
            return NULL;        // beacuse there exits no inverse
        }
        temp = normal_matrix_adjoint(matrix, row, column);
        mat = normal_matrix_transpose(temp, row, column);
        free(temp);

        for(i=0 ; i<row ; i++)
            for(j=0 ; j<column ; j++)
                *(mat + i*column + j) = *(mat + i*column + j) / det;
        return mat;
    }
}

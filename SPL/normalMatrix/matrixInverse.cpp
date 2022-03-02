#include<bits/stdc++.h>
#include "n-header.h"

using namespace std;

void matrix_inverse_withPrint_byAdj(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because matrix is NULL" <<endl;
        return;
    }
    else if (row != column) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because row and column are not same" <<endl;
        return;
    }

    else {
        int i, j , mat[row][column], *m, det;
        m = &mat[0][0];

        m = matrix_adjoint(matrix, row, column);
        det = matrix_determinant(matrix, row, column);

        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                if( *(m + i*column + j)  % det == 0) {
                    cout << *(m + i*column + j) / det << "    ";
                }
                else {
                    if(det > 0)
                        cout << *(m + i*column + j) << '/' << det << "  ";
                    else
                        cout << -*(m + i*column + j) << '/' << -det << "  ";
                }
                //cout << *(m + i*column + j) << "  ";
            }
            cout << endl;
        }
    }
}

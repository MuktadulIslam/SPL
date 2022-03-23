#include<bits/stdc++.h>
#include "fmatrix.h"

using namespace std;

int * fmatrix_inverse(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "Matrix Inverse by Adj can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j, a, b, c, det[2], *p, *mat;
        p = det;

        mat = fmatrix_adjoint(matrix, row, column);
        fmatrix_determinant(matrix, row, column, p);


        if(*p > 0) {
            for(i=0 ; i<row ; i++) {
                for(j=0 ; j<column ; j++) {
                    a = *(mat + i*column*2 + j*2);
                    a = a * (*(p+1));
                    b = *(mat + i*column*2 + j*2 + 1);
                    b = b * (*p);

                    c = gcd(a,b);
                    *(mat + i*column*2 + j*2) = a/c;
                    *(mat + i*column*2 + j*2 + 1) = b/c;
                }
            }
        }

        else {
            for(i=0 ; i<row ; i++) {
                for(j=0 ; j<column ; j++) {
                    a = *(mat + i*column*2 + j*2);
                    a = - a * (*(p+1));
                    b = *(mat + i*column*2 + j*2 + 1);
                    b = b * (-(*p));

                    c = gcd(a,b);
                    *(mat + i*column*2 + j*2) = a/c;
                    *(mat + i*column*2 + j*2 + 1) = b/c;
                }
            }
        }
        return mat;
    }
}


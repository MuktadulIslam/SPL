#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * inverse_with_fractional_Adj(int * matrix, int row, int column, int *det) {
    matrix++;

    int i,j, divisor, divident, GCD;
    if(*det > 0) {
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                divident = *(matrix + i*column*2 + j*2) * (*(det+1));

                if(divident == 0) {
                    *(matrix + i*column*2 + j*2) = 0;
                    *(matrix + i*column*2 + j*2 + 1) = 1;
                }
                else {
                    divisor = *(matrix + i*column*2 + j*2 + 1) * (*det);

                    GCD = gcd(divident,divisor);
                    *(matrix + i*column*2 + j*2) = divident/GCD;
                    *(matrix + i*column*2 + j*2 + 1) = divisor/GCD;
                }

            }
        }
    }

    else {
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                divident = - *(matrix + i*column*2 + j*2) * (*(det+1));

                if(divident == 0) {
                    *(matrix + i*column*2 + j*2) = 0;
                    *(matrix + i*column*2 + j*2 + 1) = 1;
                }
                else {
                    divisor = *(matrix + i*column*2 + j*2 + 1) * (-(*det));

                    GCD = gcd(divident,divisor);
                    *(matrix + i*column*2 + j*2) = divident/GCD;
                    *(matrix + i*column*2 + j*2 + 1) = divisor/GCD;
                }
            }
        }
    }

    return matrix_memory_optimization(--matrix, row, column);
}

int * inverse_with_normal_Adj(int * matrix, int row, int column, int *det) {

    int i,j, divisor, divident, GCD, *mat;
    mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    *mat++ = INT_MAX;

    if(*det > 0) {
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                divident = *(matrix + i*column + j) * (*(det+1));

                if(divident == 0) {
                    *(mat + i*column*2 + j*2) = 0;
                    *(mat + i*column*2 + j*2 + 1) = 1;
                }
                else {
                    divisor =  *det;

                    GCD = gcd(divident,divisor);
                    *(mat + i*column*2 + j*2) = divident/GCD;
                    *(mat + i*column*2 + j*2 + 1) = divisor/GCD;
                }

            }
        }
    }

    else {
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                divident = - *(matrix + i*column + j) * (*(det+1));

                if(divident == 0) {
                    *(mat + i*column*2 + j*2) = 0;
                    *(mat + i*column*2 + j*2 + 1) = 1;
                }
                else {
                    divisor = -(*det);

                    GCD = gcd(divident,divisor);
                    *(mat + i*column*2 + j*2) = divident/GCD;
                    *(mat + i*column*2 + j*2 + 1) = divisor/GCD;
                }
            }
        }
    }

    free(matrix);
    return matrix_memory_optimization(--mat, row, column);
}




int * matrix_inverse(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "fMatrix Inverse by Adj can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }
    else if (row != column) {
        cout << "fMatrix Inverse by Adj can't possible!!!!!!  Because row and column are not same" <<endl;
        return NULL;
    }

    else {
        int i, j, a, b, c, det[2], *p, *mat, *temp;
        p = det;

        matrix_determinant(matrix, row, column, p);

            if(*p == 0) {
                cout << "fMatrix Inverse by Adj can't possible!!!!!!  Because fmatrix determinant is zero!!!" <<endl;
                return NULL;        // beacuse there exits no inverse
            }

        temp = matrix_adjoint(matrix, row, column);
        mat = matrix_transpose(temp, row, column);
        free(temp);


        if(is_fractional_matrix(mat)) {
            return inverse_with_fractional_Adj(mat, row, column, p);
        }
        else {
            return inverse_with_normal_Adj(mat, row, column, p);
        }


    }
}


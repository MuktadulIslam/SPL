#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * matrix_multiplication_with_constant(int constant, int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Multiplication with constant can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    else if(*matrix == INT_MAX) {
        matrix++;

        int i, j, divisor, divident, GCD, *mat, *temp;
        mat = (int*) malloc(row * column * 2 * sizeof(int) + 1);
        temp = mat;
        *mat++ = INT_MAX;

        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                divident = *(matrix + i*column*2 + j*2) * constant;
                divisor = *(matrix + i*column*2 + j*2 + 1);

                if(divident == 0) {
                    *mat++ = 0;
                    *mat++ = 1;
                }
                else {
                    GCD = gcd(divident, divisor);

                    *mat++ = divident/GCD;
                    *mat++ = divisor/GCD;
                }
            }
        }
        return temp;
    }
    else{
        return normal_matrix_multiplication_with_constant(constant, matrix, row, column);
    }
}

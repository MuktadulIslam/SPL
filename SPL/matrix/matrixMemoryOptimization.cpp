#include<bits/stdc++.h>
#include "matrix.h"

using namespace std;

int * matrix_memory_optimization(int * matrix, int row, int column) {
    int i, j, GCD, *mat = matrix+1, *dividend, *divisor;
    bool flag = true;

    for(i=0 ; i<row ; i++){

        for(j=0 ; j<column ; j++){
            dividend = mat + i*column*2 + j*2;
            divisor = mat + i*column*2 + j*2 + 1 ;

            if(*dividend != 0){
                GCD = gcd(*dividend, *divisor);
                *dividend = *dividend/GCD;
                *divisor = *divisor/GCD;
            }
            else {
                *dividend = 0;
                *divisor = 1;
            }

            if(*divisor != 1){
                flag = false;
            }
        }
    }

    if(flag) {
        int *Matrix, *temp;
        Matrix = (int*) malloc(row * column * sizeof(int));
        temp = Matrix;

        for(i=0 ; i < row ; i++) {
            for(j=0 ; j < column ; j++) {
                *Matrix++ = *(mat + i*column*2 + j*2);
            }
        }

        free(matrix);
        return temp;
    }
    else{
        return matrix;
    }
}

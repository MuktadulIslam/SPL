#include<bits/stdc++.h>
#include "matrix.h"

using namespace std;

int * matrix_memory_optimization(int * matrix, int row, int column) {
    int i, j, *mat = matrix+1;
    bool flag = true;

    for(i=0 ; i<row ; i++){
        for(j=0 ; j<column ; j++){
            if(*(mat + i*column*2 + j*2 + 1) != 1){
                flag = false;
                break;
            }
        }
        if(!flag) break;
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

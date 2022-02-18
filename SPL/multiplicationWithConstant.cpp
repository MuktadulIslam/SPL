#include<bits/stdc++.h>
#include "header.h"

using namespace std;

int * matrix_multiplication_with_constant(int constant, int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "Multiplication with constant can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    int i, j, *matrix1;
    matrix1 = (int*) malloc(row * column * sizeof(int));

    for(i=0 ; i<row ; i++){
        for(j=0 ; j<column ; j++) {
            *(matrix1 + i*row + j) = (*(matrix + i*row + j)) * constant;
        }
    }
    return matrix1;
}

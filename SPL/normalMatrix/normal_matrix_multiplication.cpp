#include <bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * normal_matrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(column1 != row2) {
        cout << "Matrix Multiplication can't possible!!!!!!  Because column1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "Matrix Multiplication can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "Matrix Multiplication can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, k, *matrix, *temp, temp1;
        matrix = (int*) malloc(row1 * column2 * sizeof(int));
        temp = matrix;

        for(i=0 ; i<row1 ; i++) {
            for(j=0 ; j<column2 ; j++) {
                temp1 = 0;
                for(k=0 ; k<column1 ; k++) {
                    temp1 = temp1 + *(matrix1 + i*column1 + k) *  *(matrix2 + k*column2 + j);
                }
                *matrix = temp1;
                matrix++;
            }
        }
        return temp;
    }
}


#include<bits/stdc++.h>
#include "n-header.h"
using namespace std;

void subMatrix(int *matrix, int *newMatrix, int row, int removeRow, int removeColumn) {
    int i, j, *temp = newMatrix;
    for(i=0 ; i<row ; i++) {
        if(i == removeRow)
            continue;
        for(j=0 ; j<row ; j++) {
            if(j == removeColumn)
                continue;
            else{
                *temp = *(matrix + i*row + j);
                temp++;
            }
        }
    }
}


int matrix_determinant(int *matrix, int row, int column) {

    if(matrix == NULL) {
        cout << "Matrix Determinant can't possible!!!!!!  Because matrix is NULL" <<endl;
        return INT_MAX;
    }
    else if (row != column) {
        cout << "Matrix Determinant can't possible!!!!!!  Because row and column are not same" <<endl;
        return INT_MAX;
    }


    if(row == 1) {
        return *matrix;
    }

    else {
        int i, j, sum = 0, sign = 1, temp[row-1][row-1];
        for(i=0 ; i<row ; i++) {
            subMatrix (matrix, &temp[0][0], row, 0, i);
            sum = sum + (*(matrix+i)) * matrix_determinant(&temp[0][0], row-1, column-1) * sign;
            sign = -sign;
        }
        return sum;
    }
}

#include<bits/stdc++.h>
#include "normal_matrix.h"
#include "matrix.h"
using namespace std;

void sub_normal_matrix(int *matrix, int *newMatrix, int row, int removeRow, int removeColumn) {
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


int normal_matrix_determinant(int *matrix, int row, int column) {
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
        int i, j, k, multiplier1, multiplier2, GCD, divisor = 1;
        int *temp1, *temp2;

        // making lower triangle matrix
        for(i=0 ; i<row-1 ; i++) {
            for(j=i+1 ; j<row ; j++) {
                temp1 = (matrix + i*column + i);
                temp2 = (matrix + j*column + i);

                GCD = gcd(*temp1 , *temp2);
                multiplier1 = abs(*temp2 / GCD);
                multiplier2 = abs(*temp1 / GCD);
                divisor *= multiplier2;

                if((*temp1) * (*temp2) > 0) {    // if both are in same sign
                    for(k=0 ; k<column ; k++){
                        temp1 = matrix + i*column + k;
                        temp2 = matrix + j*column + k;

                        *temp2 = (*temp2 * multiplier2) - (*temp1 * multiplier1);
                    }
                }

                else {
                    for(k=0 ; k<column ; k++){
                        temp1 = matrix + i*column + k;
                        temp2 = matrix + j*column + k;

                        *temp2 = (*temp2 * multiplier2) + (*temp1 * multiplier1);
                    }
                }
            }
        }

        int multiplication = 1;
        for(i=0 ; i<row; i++) {
            multiplication *= *(matrix + i*column + i);
        }

        return multiplication/divisor;
    }
}

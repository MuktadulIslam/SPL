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
        int mat[row][column];

        // copy from matrix to mat, because it's going to be a upper triangler matrix
        for(i=0 ; i<row ; i++)
            for(j=0 ; j<column ; j++)
                mat[i][j] = *(matrix + i*column + j);


        // making upper triangler matrix
        for(i=0 ; i<row-1 ; i++) {
            for(j=i+1 ; j<row ; j++) {
                temp1 = &mat[i][i];
                temp2 = &mat[j][i];

                GCD = gcd(*temp1 , *temp2);
                multiplier1 = abs(*temp2 / GCD);
                multiplier2 = abs(*temp1 / GCD);
                divisor *= multiplier2;

                if((*temp1) * (*temp2) > 0) {    // if both are in same sign
                    for(k=0 ; k<column ; k++){
                        temp1 = &mat[i][k];
                        temp2 = &mat[j][k];

                        *temp2 = (*temp2 * multiplier2) - (*temp1 * multiplier1);
                    }
                }

                else {
                    for(k=0 ; k<column ; k++){
                        temp1 = &mat[i][k];
                        temp2 = &mat[j][k];

                        *temp2 = (*temp2 * multiplier2) + (*temp1 * multiplier1);
                    }
                }
            }
        }

        int multiplication = 1;
        for(i=0 ; i<row; i++) {
            multiplication *= mat[i][i];
        }

        return multiplication/divisor;
    }
}

#include <bits/stdc++.h>
#include "fmatrix.h"
#include "matrix.h"

using namespace std;

int * fmatVSfmat_mult(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    int i, j, k, LCM, temp1, temp2, sum[2];
    int *temp, *matrix;
    matrix = (int*) malloc(row1 * column2 * sizeof(int) * 2 + 1);
    temp = matrix;

    for(i=0 ; i<row1 ; i++) {
        for(j=0 ; j<column2 ; j++) {
            sum[0] = 0;      // intially .....sum = 0/1
            sum[1] = 1;
            for(k=0 ; k<column1 ; k++) {
                temp1 = *(matrix1 + i*row1*2 + k*2) *  *(matrix2 + k*row2*2 + j*2);
                temp2 = *(matrix1 + i*row1*2 + k*2 + 1) *  *(matrix2 + k*row2*2 + j*2 + 1);

                LCM = lcm(sum[1], temp2);
                sum[0] = sum[0]*LCM/sum[1] + temp1*LCM/temp2;
                sum[1] = LCM;
            }

            *matrix = sum[0];
            matrix++;
            *matrix = sum[1];
            matrix++;
        }
    }
    *matrix = INT_MAX;
    return temp;
}

int * matVSfmat_mult(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    int i, j, k, LCM, temp1, temp2, sum[2];
    int *temp, *matrix;
    matrix = (int*) malloc(row1 * column2 * sizeof(int) * 2 + 1);
    temp = matrix;
    for(i=0 ; i<row1 ; i++) {
        for(j=0 ; j<column2 ; j++) {
            sum[0] = 0;      // intially .....sum = 0/1
            sum[1] = 1;
            for(k=0 ; k<column1 ; k++) {
                temp1 = *(matrix1 + i*row1 + k) *  *(matrix2 + k*row2*2 + j*2);
                temp2 = *(matrix2 + i*row2*2 + k*2 + 1) *  1;

                LCM = temp2;
                sum[0] = sum[0]*LCM/sum[1] + temp1*LCM/temp2;
                sum[1] = LCM;
            }

            *matrix = sum[0];
            matrix++;
            *matrix = sum[1];
            matrix++;
        }
    }
    *matrix = INT_MAX;
    return temp;
}




int * fmatrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(column1 != row2) {
        cout << "fMatrix Multiplication can't possible!!!!!!  Because column1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "fMatrix Multiplication can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "fMatrix Multiplication can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        bool firstIsFmatrix = false, secondIsFmatrix = false;
        int *temp, Count;

            // Checking first matrix is fractional or not
            Count = 0;
            temp = matrix1;
            while(*temp != INT_MAX && Count <= row1 * column1 *2) {
                Count++;
                temp++;
            }
            if(Count == row1 * column1 * 2) firstIsFmatrix = true;


            // Checking second matrix is fractional or not
            Count = 0;
            temp = matrix2;
            while(*temp != INT_MAX && Count <= row2 * column2 *2) {
                Count++;
                temp++;
            }
            if(Count == row2 * column2 * 2) secondIsFmatrix = true;



        if(firstIsFmatrix && secondIsFmatrix) {
            return fmatVSfmat_mult(matrix1, row1, column1, matrix2, row2, column2);
        }
        else if(!firstIsFmatrix && secondIsFmatrix){
            return matVSfmat_mult(matrix1, row1, column1, matrix2, row2, column2);
        }
        else if(firstIsFmatrix && !secondIsFmatrix){
            return matVSfmat_mult(matrix2, row2, column2, matrix1, row1, column1);
        }
        else{
            return matrix_multiplication(matrix1, row1, column1, matrix2, row2, column2);
        }
    }
}



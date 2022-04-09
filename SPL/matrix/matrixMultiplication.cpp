#include <bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * fmatVSfmat_mult(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    int i, j, k, LCM, temp1, temp2, sum[2];
    int *temp, *matrix;
    matrix = (int*) malloc(row1 * column2 * sizeof(int) * 2 + 1);
    temp = matrix;

    *matrix++ = INT_MAX;
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
    return temp;
}

int * matVSfmat_mult(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    int i, j, k, LCM, temp1, temp2, sum[2];
    int *temp, *matrix;
    matrix = (int*) malloc(row1 * column2 * sizeof(int) * 2 + 1);
    temp = matrix;

    *matrix++ = INT_MAX;
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
    return temp;
}




int * matrix_multiplication(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
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

            // Checking first & second matrix is fractional or not
            if(*matrix1 == INT_MAX)
                firstIsFmatrix = true;
            if(*matrix2 == INT_MAX)
                secondIsFmatrix = true;


        if(firstIsFmatrix && secondIsFmatrix) {
            return fmatVSfmat_mult(++matrix1, row1, column1, ++matrix2, row2, column2);
        }
        else if(!firstIsFmatrix && secondIsFmatrix){
            return matVSfmat_mult(matrix1, row1, column1, ++matrix2, row2, column2);
        }
        else if(firstIsFmatrix && !secondIsFmatrix){
            return matVSfmat_mult(matrix2, row2, column2, ++matrix1, row1, column1);
        }
        else{
            cout << "BIndu" << endl;
            return normal_matrix_multiplication(matrix1, row1, column1, matrix2, row2, column2);
        }
    }
}



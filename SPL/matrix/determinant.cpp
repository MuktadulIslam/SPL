#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

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
                *temp = *(matrix + i*row*2 + j*2);
                temp++;
                *temp = *(matrix + i*row*2 + j*2 + 1);
                temp++;
            }
        }
    }
}


void fmat_det(int *matrix, int row, int column, int *value) {
    if(row == 1) {
        *value = *matrix;
        *(value+1) = *(matrix+1);
        return;
    }

    else {
        int i, j, *p, temp2, sum[2] = {0,1}, sign = 1, temp[(row-1)][(column-1)*2], det[2];
        p = det;
        for(i=0 ; i<row ; i++) {

            subMatrix (matrix, &temp[0][0], row, 0, i);
            fmat_det(&temp[0][0], row-1, column-1, p);       //  2/5.....*p = 2.....*(p+1) = 5


            /* For     4*| 2  5|
                         | 3  9|
            */
            *(p+1) = (*(p+1)) * (*(matrix + i*2 + 1));
            *p = (*p) * (*(matrix + i*2))*sign;
            sign = -sign;

            if(*p == 0) continue;   // because sum = sum + 0 = sum;

            // For 6/8 to 3/4
            temp2 = gcd(*(p+1), *p);
            *(p+1) = (*(p+1)) / temp2;
            *p = *p / temp2;


            temp2 = lcm(*(p+1) , sum[1]);
            sum[0] = sum[0]*temp2 / sum[1] + (*p * temp2 / (*(p+1)));
            sum[1] = temp2;
        }

        if(sum[0] != 0 ) {
            i = gcd(sum[0],sum[1]);
            *value = sum[0]/i;
            *(value+1) = sum[1]/i;
        }
        else {
            *value = 0;
            *(value+1) = 1;
        }
    }
}

void matrix_determinant(int *matrix, int row, int column, int *value) {
    if(matrix == NULL) {
        cout << "fMatrix Determinant can't possible!!!!!!  Because matrix is NULL" <<endl;
        return;
    }
    else if (row != column) {
        cout << "fMatrix Determinant can't possible!!!!!!  Because row and column are not same" <<endl;
        return;
    }

    if(*matrix == INT_MAX)
        fmat_det(matrix+1, row, column, value);
    else {
        *value = normal_matrix_determinant(matrix, row, column);
        *(value+1) = 1;
    }
}


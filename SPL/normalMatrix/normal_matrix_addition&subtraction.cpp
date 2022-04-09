#include<bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * normal_matrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(row1 != row2) {
        cout << "Matrix addition can't possible!!!!!!  Because row1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(column1 != column2) {
        cout << "Matrix addition can't possible!!!!!!  Because column1 and column2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "Matrix addition can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "Matrix addition can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *matrix, *temp;
        matrix = (int*) malloc(row1 * column1 * sizeof(int));
        temp = matrix;

        for(i=0 ; i<row1 ; i++) {
            for(j=0 ; j<column1 ; j++) {
                *matrix = *(matrix1 + i*column1 + j) + *(matrix2 + i*column2 + j);
                matrix++;
            }
        }
        return temp;
    }
}


int * normal_matrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(row1 != row2) {
        cout << "Matrix subtraction can't possible!!!!!!  Because row1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(column1 != column2) {
        cout << "Matrix subtraction can't possible!!!!!!  Because column1 and column2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "Matrix subtraction can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "Matrix subtraction can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *matrix, *temp;
        matrix = (int*) malloc(row1 * column1 * sizeof(int));
        temp = matrix;

        for(i=0 ; i<row1 ; i++) {
            for(j=0 ; j<column1 ; j++) {
                *matrix = *(matrix1 + i*column1 + j) - *(matrix2 + i*column2 + j);
                matrix++;
            }
        }
        return temp;
    }
}



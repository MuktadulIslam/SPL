#include<bits/stdc++.h>
#include "fmatrix.h"

using namespace std;

int * fmatrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(row1 != row2) {
        cout << "fMatrix addition can't possible!!!!!!  Because row1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(column1 != column2) {
        cout << "fMatrix addition can't possible!!!!!!  Because column1 and column2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "fMatrix addition can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "fMatrix addition can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *matrix, *temp, t, t1, t2;
        matrix = (int*) malloc(row1 * column1 * sizeof(int) * 2 + 1);
        temp = matrix;

        for(i=0 ; i<row1 ; i++) {
            for(j=0 ; j<column1 ; j++) {
                t = lcm( *(matrix1 + i*column1*2 + j*2 + 1), *(matrix2 + i*column1*2 + j*2 + 1));       // for smallest common multiple
                t1= t / *(matrix1 + i*column1*2 + j*2 + 1);
                t2 = t/ *(matrix2 + i*column1*2 + j*2 + 1);

                if( *(matrix1 + i*column1*2 + j*2 + 1) == *(matrix2 + i*column1*2 + j*2 + 1) ) {
                    *matrix = *(matrix1 + i*column1*2 + j*2) + *(matrix2 + i*column1*2 + j*2) ;
                    matrix++;
                    *matrix = *(matrix1 + i*column1*2 + j*2 + 1);
                    matrix++;
                }

                else{
                    *matrix = *(matrix1 + i*column1*2 + j*2)*t1  +  *(matrix2 + i*column1*2 + j*2)*t2 ;
                    matrix++;
                    *matrix = t;
                    matrix++;
                }
            }
        }
        *matrix = INT_MAX;
        return temp;
    }
}


int * fmatrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
    if(row1 != row2) {
        cout << "fMatrix addition can't possible!!!!!!  Because row1 and row2 are not same" <<endl;
        return NULL;
    }
    else if(column1 != column2) {
        cout << "fMatrix addition can't possible!!!!!!  Because column1 and column2 are not same" <<endl;
        return NULL;
    }
    else if(matrix1 == NULL) {
        cout << "fMatrix addition can't possible!!!!!!  Because matrix1 is NULL" <<endl;
        return NULL;
    }
    else if(matrix2 == NULL) {
        cout << "fMatrix addition can't possible!!!!!!  Because matrix2 is NULL" <<endl;
        return NULL;
    }

    else {
        int i, j, *matrix, *temp, t, t1, t2;
        matrix = (int*) malloc(row1 * column1 * sizeof(int) * 2 + 1);
        temp = matrix;

        for(i=0 ; i<row1 ; i++) {
            for(j=0 ; j<column1 ; j++) {
                t = lcm( *(matrix1 + i*column1*2 + j*2 + 1), *(matrix2 + i*column1*2 + j*2 + 1));       // for smallest common multiple
                t1= t / *(matrix1 + i*column1*2 + j*2 + 1);
                t2 = t/ *(matrix2 + i*column1*2 + j*2 + 1);

                if( *(matrix1 + i*column1*2 + j*2 + 1) == *(matrix2 + i*column1*2 + j*2 + 1) ) {
                    *matrix = *(matrix1 + i*column1*2 + j*2) - *(matrix2 + i*column1*2 + j*2) ;
                    matrix++;
                    *matrix = *(matrix1 + i*column1*2 + j*2 + 1);
                    matrix++;
                }

                else{
                    *matrix = *(matrix1 + i*column1*2 + j*2)*t1  -  *(matrix2 + i*column1*2 + j*2)*t2 ;
                    matrix++;
                    *matrix = t;
                    matrix++;
                }
            }
        }
        *matrix = INT_MAX;
        return temp;
    }
}


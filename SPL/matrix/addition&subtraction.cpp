#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * fmatVSfmat_add(int *matrix1, int *matrix2, int row, int column) {
    int i, j, *matrix, *temp, LCM, m1, m2, fm1, fm2;
    matrix = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    temp = matrix;

    *matrix++ = INT_MAX;

    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            m1 = *(matrix1 + i*column*2 + j*2);
            m2 = *(matrix1 + i*column*2 + j*2 + 1);
            fm1 = *(matrix2 + i*column*2 + j*2);
            fm2 = *(matrix2 + i*column*2 + j*2 + 1);

            if( m2 == fm2) {
                *matrix = m1 + fm1;
                matrix++;
                *matrix = m2;
                matrix++;
            }

            else{
                LCM = lcm( m2, fm2);       // for smallest common multiple
                *matrix = m1*LCM/m2  +  fm1*LCM/fm2 ;
                matrix++;
                *matrix = LCM;
                matrix++;
            }
        }
    }
    return temp;
}

int * matVSfmat_add(int *matrix, int *fmatrix, int row, int column) {
    int i, j, *mat, *temp, LCM, m1, fm1, fm2 ;
    mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    temp = mat;

    *mat++ = INT_MAX;

    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            m1 = *(matrix + i*column + j);
            fm1 = *(fmatrix + i*column*2 + j*2);
            fm2 = *(fmatrix + i*column*2 + j*2 + 1);


            *mat = m1*fm2  +  fm1;
            mat++;
            *mat= fm2;
            mat++;
        }
    }
    return temp;
}

int * fmatVSfmat_subtraction(int *matrix1, int *matrix2, int row, int column) {
    int i, j, *matrix, *temp, LCM, m1, m2, fm1, fm2;
    matrix = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    temp = matrix;

    *matrix++ = INT_MAX;

    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            m1 = *(matrix1 + i*column*2 + j*2);
            m2 = *(matrix1 + i*column*2 + j*2 + 1);
            fm1 = *(matrix2 + i*column*2 + j*2);
            fm2 = *(matrix2 + i*column*2 + j*2 + 1);

            if( m2 == fm2) {
                *matrix = m1 - fm1;
                matrix++;
                *matrix = m2;
                matrix++;
            }

            else{
                LCM = lcm( m2, fm2);       // for smallest common multiple
                *matrix = m1*LCM/m2  -  fm1*LCM/fm2 ;
                matrix++;
                *matrix = LCM;
                matrix++;
            }
        }
    }
    return temp;
}

int * matVSfmat_subtraction(int *matrix, int *fmatrix, int row, int column) {
    int i, j, *mat, *temp, LCM, m1, fm1, fm2 ;
    mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    temp = mat;

    *mat++ = INT_MAX;

    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            m1 = *(matrix + i*column + j);
            fm1 = *(fmatrix + i*column*2 + j*2);
            fm2 = *(fmatrix + i*column*2 + j*2 + 1);


            *mat = m1*fm2  -  fm1;
            mat++;
            *mat= fm2;
            mat++;
        }
    }
    return temp;
}

int * fmatVSmat_subtraction(int *fmatrix, int *matrix, int row, int column) {
    int i, j, *mat, *temp, LCM, m1, fm1, fm2 ;
    mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
    temp = mat;

    *mat++ = INT_MAX;

    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            m1 = *(matrix + i*column + j);
            fm1 = *(fmatrix + i*column*2 + j*2);
            fm2 = *(fmatrix + i*column*2 + j*2 + 1);


            *mat = fm1 - m1*fm2;
            mat++;
            *mat= fm2;
            mat++;
        }
    }
    return temp;
}



int * matrix_addition(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
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
        if(*matrix1 == INT_MAX && *matrix2 == INT_MAX)
            return matrix_memory_optimization( fmatVSfmat_add(matrix1+1, matrix2 + 1, row2, column2), row1, column1);

        else if(*matrix1 == INT_MAX)
            return matrix_memory_optimization( matVSfmat_add(matrix2, matrix1+1, row1, column1), row1, column1);

        else if(*matrix2 == INT_MAX)
            return matrix_memory_optimization( matVSfmat_add(matrix1, matrix2+1, row2, column2), row1, column1);

        else
            return normal_matrix_addition( matrix1, row1, column1, matrix2, row2, column2);
    }
}


int * matrix_subtraction(int *matrix1, int row1, int column1, int *matrix2, int row2, int column2) {
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
        if(*matrix1 == INT_MAX && *matrix2 == INT_MAX)
            return matrix_memory_optimization( fmatVSfmat_subtraction(matrix1+1, matrix2+1, row2, column2), row1, column1);

        else if(*matrix1 == INT_MAX)
            return matrix_memory_optimization( fmatVSmat_subtraction(matrix1+1, matrix2, row1, column1), row1, column1);

        else if(*matrix2 == INT_MAX)
            return matrix_memory_optimization( matVSfmat_subtraction(matrix1, matrix2+1, row2, column2), row1, column1);

        else
            return normal_matrix_subtraction(matrix1, row1, column1, matrix2, row2, column2);
    }
}


#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * matrix_transpose(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "fMatrix Transpose can't possible!!!!!!  Because matrix is NULL" <<endl;
        return NULL;
    }

    else if(*matrix == INT_MAX)
    {
        matrix++;

        int i, j, *mat, *temp;
        mat = (int*) malloc((row * column  * 2 + 1)*sizeof(int));
        temp = mat;
        *mat++ = INT_MAX;

        for(i=0 ; i<column ; i++) {
            for(j=0 ; j<row; j++) {
                *mat = *(matrix + j*column*2 + i*2);
                mat++;
                *mat = *(matrix + j*column*2 + i*2 + 1);
                mat++;
            }
        }
        return matrix_memory_optimization(temp, column, row);
    }
    else
        return normal_matrix_transpose(matrix, row, column);
}

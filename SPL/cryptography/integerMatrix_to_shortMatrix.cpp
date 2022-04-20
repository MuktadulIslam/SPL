#include <bits/stdc++.h>
#include "cryptography.h"

using namespace std;

short * integerMatrix_to_shortMatrix(int *matrix, int row, int column) {
    short *mat, *temp1;
    int i, j, *temp2;
    mat = (short*) malloc((row * column)*sizeof(short));

    temp1 = mat;
    temp2 = matrix;
    for(i=0 ; i<row ; i++)
        for(j=0 ; j<column ; j++)
            *temp1++ = (short) *temp2++;

    free(matrix);   // beacuse in future, this matrix will not used
    return mat;

}

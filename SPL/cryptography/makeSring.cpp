#include <bits/stdc++.h>
#include "cryptography.h"
#include "matrix.h"

using namespace std;

string matrixToString(int *matrix, int row, int column) {
//    print_matrix(matrix, row, column);
    string str = "";
    int i, j;

    for(i=0 ; i<row; i++) {
        for(j=0 ; j<column ; j++) {
            if(*matrix == 0)
                return str;
            else {
                str += (char)*matrix;
                matrix++;
            }
        }
    }
    return str;
}

#include <bits/stdc++.h>
#include "cryptography.h"

using namespace std;

string matrixToString(int *matrix, int row, int column) {
    string str = "";
    int i, j;

    for(i=0 ; i<row; i++) {
        for(j=0 ; j<column ; j++) {
            str += (char)*matrix;
            matrix++;
        }
    }
    return str;
}

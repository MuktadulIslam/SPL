#include<bits/stdc++.h>
using namespace std;

void print_fmatrix(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "The matrix is empty!!!!!" << endl;
        return;
    }

    else {
        int i, j;
        for(i=0 ; i<row ; i++){
            for(j=0 ; j<column ; j++) {
                cout << *(matrix + i*column*2 + j*2) << '/' << *(matrix + i*column*2 + j*2 + 1) << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

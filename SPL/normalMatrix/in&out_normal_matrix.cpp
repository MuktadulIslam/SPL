#include<bits/stdc++.h>
#include "normal_matrix.h"

using namespace std;

int * input_normal_matrix_from_file(char *fileName, int *row, int *column){
    fstream file;
    file.open(fileName);

    if(!file.is_open()) {
        cout << "Failed to open the \"" << fileName << "\" file!!!!!!" << endl;
        return NULL;
    }

    else {
        file >> *row >> *column;

        int i, j, *matrix ;
        matrix = (int*) malloc((*row) * (*column) * sizeof(int));

        for(i=0 ; i < *row ; i++)
            for(j=0 ; j < *column ; j++)
                file >> *(matrix + i*(*column) + j);

        file.close();
        return matrix;
    }
}


int * input_normal_matrix_from_console(int *row, int *column){
    int i, j, *matrix ;
    cout << "Enter the number of row and column:  ";
    cin >> *row >> *column;

    matrix = (int*) malloc((*row) * (*column) * sizeof(int));

    cout << "Now enter the  " << *row << 'X' << *column << "  Matrix:" << endl;
    for(i=0 ; i < *row ; i++)
        for(j=0 ; j < *column ; j++)
            cin >> *(matrix + i*(*column) + j);

    return matrix;
}

 void print_normal_matrix(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "The matrix is empty!!!!!" << endl;
        return;
    }
    else {
        int i, j;
        for(i=0 ; i<row ; i++){
            for(j=0 ; j<column ; j++) {
                cout << *(matrix + i*column + j) << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
 }


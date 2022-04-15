#include<bits/stdc++.h>
#include "normal_matrix.h"
#include "matrix.h"
#include "linearSystem.h"

using namespace std;

void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName) {
    int i, j ,k;
    string str;
    int a, b,row, column, *matrix1, *matrix2, *dMat, *mat;
    char *variables, *var;
    input_equation_from_file(equationFileName, &row, &column, &matrix1, &dMat, &variables);
    print_matrix(matrix1, row, column);
    print_matrix(dMat, row, 1);

//    char v[] = {'x','y', 'z'};
//    variables = v;
//
//    dMat = input_matrix_from_file("text2.txt", &a, &b);
//    print_matrix(dMat, a, b);
//    matrix1 = input_matrix_from_file("text3.txt",&row, &column);
//    print_matrix(matrix1, row, column);

    ifstream read (equationFileName);
    ofstream write (solutionFileName);

    if(!read.is_open()) {
        cout << "Failed to open the \"" << equationFileName << "\" file!!!!!!" << endl;
        return;
    }
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }


    write << "\t\t*******Solution of linear system using Cramer's law*******" << endl << endl;
        read >> row;
        int del_x[row], del;
        read.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer
        write << "Given, the systems of linear equations:" << endl;
        for(i=0 ; i<row ; i++) {
            getline(read, str);
            write << "\t\t\t" << str << endl;
        }

    // Creating [X] = [A]-1[B]
//    cout << row << column << endl;

    matrix2 = matrix_inverse(matrix1, row, column);
    print_matrix(matrix2, row, column);
    matrix2 = matrix_multiplication(matrix2, row, column, dMat, a, b);
    print_matrix(matrix2, row, 1);

    // Writhing in file
    write << "\n\n\n";
    for(i=0 ; i<row ; i++){
        write << "\t  " << *(variables+i) << " = " << *(matrix1+i*2) << "/" << *(matrix1+i*2+1);
        write << endl << endl;
    }

    write.close();
    read.close();
    cout << "row = " << row << "    column = " << column << endl;
}

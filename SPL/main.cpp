#include<bits/stdc++.h>
#include "header.h"

using namespace std;

int main(void) {

    //matrix
    int row1, column1, *matrix1;
    int row2, column2, *matrix2;
    int *matrix3;

    matrix1 = input_matrix_from_file("text.txt", &row1, &column1);
    //matrix1 = input_matrix_from_console(&row1, &column1);
    printMatrix(matrix1, row1, column1);
    //cout << matrix_determinant(matrix1, row1, column1);

    //matrix2 = input_matrix_from_file("text2.txt", &row2, &column2);
    //printMatrix(matrix2, row2, column2);

    //matrix3 = matrix_addition(matrix1, row1, column1, matrix2, row2, column2);
    //printMatrix(matrix3, row1, column1);

    //matrix3 = matrix_subtraction(matrix1, row1, column1, matrix2, row2, column2);
    //printMatrix(matrix3, row1, column1);

    //matrix3 = matrix_multiplication(matrix1, row1, column1, matrix2, row2, column2);
    //printMatrix(matrix3,row1, column2);

    //cout << row1 << "   " << column1;
    //matrix2 = matrix_multiplication_with_constant(2, matrix1, row1, column1);
    //printMatrix(matrix2,row1, column1);


    return 0;
}

#include<bits/stdc++.h>
#include "matrix.h"
#include "fmatrix.h"
#include "linearSystem.h"

using namespace std;

int main(void) {
    int i,j,k = 0,row, column, *matrix, det[2], *matrix2, *matrix3, *matrix4;
//    matrix = input_matrix_from_file("text1.txt",&row, &column);
//    matrix2 = matrix_multiplication(matrix, row, row, matrix,row, row);
//    print_fmatrix(matrix2, row, column);

    matrix3 = input_fmatrix_from_file("text1.txt",&row, &column);
    matrix4 = fmatrix_addition(matrix3, row, row, matrix3,row, row);
    print_fmatrix(matrix4, row, column);
//
//
//    matrix4 = fmatrix_multiplication(matrix, row, row, matrix3,row, row);
//    print_fmatrix(matrix4, row, column);

//    cout << sizeof(matrix);
//    matrix = input_fmatrix_from_console(&row, &column);
//    fmatrix_determinant(matrix, row, column, &det[0]);
//    cout << det[0] << '/' << det[1] << endl;
//    matrix2 = fmatrix_inverse(matrix, row, column);
//    matrix = fmatrix_subtraction(matrix, row, column, matrix, row, column);
//    print_fmatrix(matrix, row, column);
//    solution_by_cramersRules("equation.txt", "solution2.txt");

    //print_fmatrix(matrix, row, column);







    /*bool v = true;
    int choice1, choice2, choice3, choice4;
        cout << "1. Matrix Operation" << endl;
        cout << "2. Linera System Solver" << endl;
        cout << "\n\t Enter your choice:  ";
        cin >> choice1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer


        if(choice1 == 1) {
            int *mat, *matrix1, *matrix2, row1, row2, column1, column2;
            cout <<"\t1. Input From file " << endl;
            cout <<"\t2. Input From Console" << endl;
            cout << "\n\t\t Enter your choice:  ";
            cin >> choice2;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

            if(choice2 == 1){
                char str1[100], str2[100];
                cout << "Enter 1st file name:  ";
                cin >> str1;
                cout << "Enter 2nd file name:  ";
                cin >> str2;

                matrix1 = input_matrix_from_file(str1, &row1, &column1);
                matrix2 = input_matrix_from_file(str2, &row2, &column2);
            }
            else if(choice2 == 2){
                matrix1 = input_matrix_from_console(&row1, &column1);
                matrix2 = input_matrix_from_console(&row2, &column2);
            }
            else {
                cout << "Invalid choice!!!!\n";
            }

            cout << "1. Matrix Addition" << endl;
            cout << "2. Matrix Subtraction" << endl;
            cout << "3. Matrix Multiplication" << endl;
            cout << "4. Matrix Determinant" << endl;
            cout << "5. Matrix Adjoint" << endl;
            cout << "6. Matrix Inverse" << endl;
            cout << "7. Matrix Transpose" << endl;

            cout << "\n\t Enter your choice:  ";
            cin >> choice3;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

            if(choice3 == 1) {
                mat = matrix_addition(matrix1, row1, column1,matrix2, row2, column2);
                print_matrix(mat, row1, column1);
            }
            else if(choice3 == 2) {
                mat = matrix_subtraction(matrix1, row1, column1,matrix2, row2, column2);
                print_matrix(mat, row1, column1);
            }
            else if(choice3 == 3) {
                mat = matrix_multiplication(matrix1, row1, column1,matrix2, row2, column2);
                print_matrix(mat, row1, column2);
            }
            else if(choice3 == 4) {
                cout << "\t\tWhich matrix???     1. 1st matrix     2. 2nd matrix" << endl;
                cout << "\n\t\t Enter your choice:  ";
                cin >> choice4;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

                if(choice4 == 1) {
                    cout << "Determinant of 1st matrix :  " << matrix_determinant(matrix1, row1, column1);
                }
                else if(choice4 == 2) {
                    cout << "Determinant of 1st matrix :  " << matrix_determinant(matrix2, row2, column2);
                }
                else {
                    cout << "Invalid choice!!!!\n";
                }
            }
            else if(choice3 == 5) {
                cout << "\t\tWhich matrix???     1. 1st matrix     2. 2nd matrix" << endl;
                cout << "\n\t\t Enter your choice:  ";
                cin >> choice4;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

                if(choice4 == 1) {
                    mat = matrix_adjoint(matrix1, row1, column1);
                    print_matrix(mat, row1, column1);
                }
                else if(choice4 == 2) {
                    mat = matrix_adjoint(matrix2, row2, column2);
                    print_matrix(mat, row2, column2);
                }
                else {
                    cout << "Invalid choice!!!!\n";
                }
            }
            else if(choice3 == 6) {
                cout << "\t\tWhich matrix???     1. 1st matrix     2. 2nd matrix" << endl;
                cout << "\n\t\t Enter your choice:  ";
                cin >> choice4;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

                if(choice4 == 1) {
                    mat = matrix_inverse(matrix1, row1, column1);
                    print_matrix(mat, row1, column1);
                }
                else if(choice4 == 2) {
                    mat = matrix_inverse(matrix2, row2, column2);
                    print_matrix(mat, row2, column2);
                }
                else {
                    cout << "Invalid choice!!!!\n";
                }
            }
            else if(choice3 == 7) {
                cout << "\t\tWhich matrix???     1. 1st matrix     2. 2nd matrix" << endl;
                cout << "\n\t\t Enter your choice:  ";
                cin >> choice4;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

                if(choice4 == 1) {
                    mat = matrix_transpose(matrix1, row1, column1);
                    print_matrix(mat, row1, column1);
                }
                else if(choice4 == 2) {
                    mat = matrix_transpose(matrix2, row2, column2);
                    print_matrix(mat, row2, column2);
                }
                else {
                    cout << "Invalid choice!!!!\n";
                }
            }
            else {
                cout << "Invalid choice!!!!\n";
            }
        }

        else if(choice1 == 2) {
            char str[100];
            cout << "Enter the equation file name: ";
            cin >> str;

            cout << endl << "\t 1. By Cramer's low" << endl;
            cout << endl << "\t 2. By Inverse Matrix low" << endl;
            cout << "\tEnter your choice:  ";
            cin >> choice4;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer
            if(choice4 == 1) {
                solution_by_cramersRules(str , "solution1.txt");
            }
            else if(choice4 == 2) {
                solution_by_inverseMatrix(str , "solution2.txt");
            }
            else {
                cout << "Invalid choice!!!!\n";
            }
        }
        else {
            cout << "Invalid choice!!!!\n";
        }*/
}


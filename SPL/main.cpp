#include<bits/stdc++.h>
#include "matrix.h"
#include "linearSystem.h"
#include "normal_matrix.h"
#include "cryptography.h"

using namespace std;

void matrixCalculator(void);
void linearSystemSolving(void);
void encryptionDecryption(void);
void stringToArray(string str);

char fileName[200];

int main(void) {
    int choice;

    while(true) {
        cout << endl << endl;
        cout << "\t 1. Matrix Calculator" << endl;
        cout << "\t 2. Linear System Solving" << endl;
        cout << "\t 3. Encryption & Decryption" << endl;
        cout << "\t 4. Exit" << endl;

        cout << "Enter your choice = ";
        cin >> choice;


        if(choice == 1)
            matrixCalculator();
        else if(choice == 2)
            linearSystemSolving();
        else if(choice == 3)
            encryptionDecryption();
        else if(choice == 4)
            break;
        else
            cout << "\nEnter Valid Choice";
    }
}


void matrixCalculator(void) {
    int choice, choice2;
    char file1[100], file2[100];
    int row1, row2, column1, column2, *matrix1, *matrix2, constant;

    while(true) {
        cout << endl << endl;
        cout << "\t 1. Addition" << endl;
        cout << "\t 2. Subtraction" << endl;
        cout << "\t 3. Multiplication" << endl;
        cout << "\t 4. Multiplication with Constant" << endl;
        cout << "\t 5. Determinant" << endl;
        cout << "\t 6. Adjoint Matrix" << endl;
        cout << "\t 7. Inverse Matrix" << endl;
        cout << "\t 8. Transpose Matrix" << endl;
        cout << "\t 9. Exit" << endl;

        cout << "Enter your choice = ";
        cin >> choice;
        cout << endl << endl;

        if(choice == 1 || choice == 2 || choice == 3) {
            cout << " 1. Read from file" << endl;
            cout << " 2. Read from Console" << endl;
            cout << "\t Enter your choice = ";
            cin >> choice2;

            if(choice2 == 1) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Enter 1st file name = ";
                cin >> file1;
                cout << "Enter 2nd file name = ";
                cin >> file2;
                matrix1 = input_matrix_from_file(file1, &row1, &column1);
                matrix2 = input_matrix_from_file(file2, &row2, &column2);

            }
            else if(choice2 == 2) {
                matrix1 = input_matrix_from_console(&row1, &column1);
                matrix2 = input_matrix_from_console(&row2, &column2);
            }
            else {
                cout << "Enter Valid Choice";
            }


            if(choice == 1)
                print_matrix(matrix_addition(matrix1,row1, column1, matrix2, row2, column2), row1, column1);
            else if(choice == 2)
                print_matrix(matrix_subtraction(matrix1,row1, column1, matrix2, row2, column2), row1, column1);
            else
                print_matrix(matrix_multiplication(matrix1,row1, column1, matrix2, row2, column2), row1, column2);
        }

        else if(choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8) {
            cout << " 1. Read from file" << endl;
            cout << " 2. Read from Console" << endl;
            cout << "\t Enter your choice = ";
            cin >> choice2;

            if(choice2 == 1) {
                string s;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Enter the file name = ";
                cin >> file1;
                matrix1 = input_matrix_from_file(file1, &row1, &column1);
            }
            else if(choice2 == 2) {
                matrix1 = input_matrix_from_console(&row1, &column1);
            }
            else {
                cout << "Enter Valid Choice";
            }


            if(choice == 4){
                cout << "\t Enter the value of constant = ";
                cin >> constant;
                print_matrix(matrix_multiplication_with_constant(constant, matrix1, row1, column1), row1, column1);
            }
            else if(choice == 5) {
                int det[2];
                matrix_determinant(matrix1, row1, column1, det);
                if(det[1] == 1)
                    cout << "The determinant is " << det[0];
                else
                    cout << "The determinant is " << det[0] << "/" << det[1];
            }
            else if(choice == 6)
                print_matrix(matrix_adjoint(matrix1, row1, column1), row1, column1);
            else if(choice == 7)
                print_matrix(matrix_inverse(matrix1, row1, column1), row1, column1);
            else if(choice == 8)
                print_matrix(matrix_transpose(matrix1, row1, column1), column1, row1);
        }
        else if(choice == 9)
            break;
        else {
            cout << "Enter Valid Choice";
        }
    }
}


void linearSystemSolving(void) {
    int choice;
    char file[100];

    while(true) {
        cout << endl << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter Equation file name = ";
        gets(file);


        cout << "\t 1. Gauss Jordan Method" << endl;
        cout << "\t 2. Gaussian Elimination" << endl;
        cout << "\t 3. Inverse Matrix" << endl;
        cout << "\t 4. Cramer's Rules" << endl;
        cout << "\t 5. Gauss Jacobi Iteration Method" << endl;
        cout << "\t 6. Gauss Seidel Iteration Method" << endl;
        cout << "\t 7. Exit" << endl;

        cout << "Enter your choice = ";
        cin >> choice;
        cout << endl;

        if(choice == 1)
            solution_by_GaussJordanMethod(file, "solution3.txt");
        else if(choice == 2)
            solution_by_GaussianElimination(file, "solution4.txt");
        else if(choice == 3)
            solution_by_inverseMatrix(file, "solution2.txt");
        else if(choice == 4)
            solution_by_cramersRules(file, "solution1.txt");
        else if(choice == 5)
            gauss_jacobi_iteration_method(file);
        else if(choice == 6)
            gauss_seidel_iteration_method(file);
        else if(choice == 7)
            break;
        else
            cout << "Enter Valid Choice";
    }
}


void encryptionDecryption(void) {
    int choice;
    string file;

    while(true) {
        cout << endl << endl;
        cout << "\t 1. Encryption" << endl;
        cout << "\t 2. Decryption" << endl;
        cout << "\t 3. Exit" << endl;

        cout << "Enter your choice = ";
        cin >> choice;
        cout << endl;

        if(choice == 1) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter Plain Text file name = ";
            cin >> file;

            encryption(file, "encryptedText.bin");
        }
        else if(choice == 2) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter Encrypted Text file name = ";
            cin >> file;

            decryption("encryptedText.bin", file);
        }
        else if(choice == 3)
            break;
        else
            cout << "Enter Valid Choice";
    }
}






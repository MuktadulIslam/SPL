#include<bits/stdc++.h>
#include "normal_matrix.h"
#include "matrix.h"
#include "linearSystem.h"

using namespace std;

int * new_matrix(int *realMatrix, int row, int column, int *copyMatrix, int insertedColumnNo) {
    int i,j, *mat;
    mat = (int*) malloc(row * column * sizeof(int));

    for(i=0 ; i <row ; i++){
        for(j=0 ; j<column ; j++) {
            if(j == insertedColumnNo){
                *(mat + i*column + j) = *copyMatrix++;
                realMatrix++;
            }
            else
                *(mat + i*column + j) = *realMatrix++;
        }
    }
    return mat;

}


void solution_by_cramersRules(char *equationFileName, char *solutionFileName) {
    int i, j ,k, maxSize;
    string str;
    int row, column, *coefficientMatrix, *dMat, *mat;
    char *variables, *var;

    // Converting the linera equation to matrix form
    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);
    int del_x[row], del;


    i = max_length_of_number(coefficientMatrix, row, column);
    j = max_length_of_number(dMat, row, 1);
    if(i<j)
        maxSize = j;
    else
        maxSize = i;


    write_introduction_part("Cramer's law", equationFileName, solutionFileName, coefficientMatrix, row, column, dMat, variables);


    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }


    /* For
    Now,
              | 2  -3   4  |
        DEL = | 1   4  -5  | = -8
              | 5  -1   1  |
    */
        write << "\nNow," << endl;
        for(i=0 ; i<row ; i++){
            if(i == row/2)
             write << "      DEL = |";
            else
                write << "\t\t\t" << "|";

            for(j=0 ; j<column ; j++) {
                write << setw(maxSize) << *(coefficientMatrix + i*column + j) << " ";
            }
            write << "|" ;

            if(i == row/2) {
                del = normal_matrix_determinant(coefficientMatrix, row, column);
                write << " = " << del;
            }
            write << endl;
        }
        write << endl;



    /* For
            | 2  -3   4  |
    DEL.x = | 1   4  -5  | = -3
            | 5  -1   1  |
    */
        for(k=0 ; k<row ; k++) {
            mat = new_matrix(coefficientMatrix, row, column, dMat, k);

            for(i=0 ; i<row ; i++){
                if(i == row/2)
                write << "\tDEL." << *(variables + k) << " = |";
                else
                    write << "\t\t\t" << "|";

                for(j=0 ; j<column ; j++) {
                    write << setw(maxSize) << *(mat + i*column + j) << " ";
                }
                write << "|" ;

                if(i == row/2) {
                    del_x[k] = normal_matrix_determinant(mat, row, column);
                    write << " = " << del_x[k];
                }
                write << endl;
            }
            write << endl;
        }



    /* For
    So now we can get the value using this method...x = (DEL.x)/DEL

      x = (DEL.x)/DEL
        = 69/-7
        = -69/7
    */

        write << endl << "So now we can get the value using this method...x = (DEL.x)/DEL" << endl << endl;

        int GCD;
        for(k=0 ; k<row ; k++) {
            write << "\t\t  " << *(variables+k) << " = (DEL." << *(variables+k) << ")/DEL" << endl;
            write << "\t\t    = " << del_x[k] << '/' << del << endl;

            GCD = gcd(del_x[k], del);
            if(GCD == 1){
                write << endl;
            }
            else {
                if(del < 0) {
                    if(-del/GCD == 1)
                        write << "\t\t    = " << -del_x[k]/GCD << endl;
                    else
                        write << "\t\t    = " << -del_x[k]/GCD << '/' << -del/GCD << endl;
                }
                else{
                    if(del/GCD == 1)
                        write << "\t\t    = " << del_x[k]/GCD << endl;
                    else
                        write << "\t\t    = " << del_x[k]/GCD << '/' << del/GCD << endl;
                }
            }

        }


    write.close();

    cout << endl << "Solution is successfully written in \"" << solutionFileName << "\"" << endl;
}


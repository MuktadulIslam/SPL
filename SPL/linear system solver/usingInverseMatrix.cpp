#include<bits/stdc++.h>
#include "matrix.h"
#include "linearSystem.h"

using namespace std;

int *matrix;

void write_2nd_part_in_SolutionByInvers(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[], char variables[]) {
    int i, j, maxLength;

    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }

/* For
    |x|   |  2  -3   4  |(-) | 3 |
    |y| = |  1   4  -5  |    | 0 |
    |z|   |  5  -1   1  |    | 5 |
*/
    maxLength = max_length_of_number(coefficientMatrix, row, column);
    for(i=0 ; i<row ; i++){
        // to fit equal sign
        if(i == row/2)
            write << "  =>  | " << variables[i] << " |  =  |";
        else
            write << "      | " << variables[i] << " |     |";


        for(j=0 ; j<column ; j++)
            write << setw(maxLength) << *(coefficientMatrix + i*column + j) << "  ";

        // to print "(-)"
        if(i == 0)
            write << "|(-) | " << setw(maxLength) << dMat[i] << " |" << endl;
        else
            write << "|    | " << setw(maxLength) << dMat[i] << " |" << endl;
    }



/* For
    |x|   |  2  -3   4  |   | 3 |
    |y| = |  1   4  -5  | x | 0 |
    |z|   |  5  -1   1  |   | 5 |
*/
    matrix = matrix_inverse(coefficientMatrix, row, column);
    maxLength = max_length_of_number(matrix, row, column);

    write << endl;
    if(is_fractional_matrix(matrix)) {
        matrix++;
        for(i=0 ; i<row ; i++){
            // to fit equal sign
            if(i == row/2)
                write << "  =>  | " << variables[i] << " |  =  |";
            else
                write << "      | " << variables[i] << " |     |";


            for(j=0 ; j<column ; j++) {
                if(*(matrix + i*column*2 + 1) == 1)
                    write << setw(maxLength) << *(matrix + i*column*2) << "  ";
                else
                    write << setw(maxLength) << *(matrix + i*column*2) << "/" << *(matrix + i*column*2+1) << "  ";
            }


            write<< "|   | " << dMat[i] << " |" << endl;
        }
        matrix--;
    }
    else {
        for(i=0 ; i<row ; i++){
            // to fit equal sign
            if(i == row/2)
                write << "  =>  | " << variables[i] << " |  =  |";
            else
                write << "      | " << variables[i] << " |     |";


            for(j=0 ; j<column ; j++)
                write << setw(maxLength) << *(matrix + i*column + j) << "  ";

            write << "|   | " << setw(maxLength) << dMat[i] << " |" << endl;
        }
    }

    write.close();
}


void write_3rd_part_in_SolutionByInvers(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[], char variables[]) {
    int i, j, maxLength;

    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }

/* For
    |x|   | 3 |
    |y| = | 0 |
    |z|   | 5 |
*/
    write << endl;
    matrix = matrix_multiplication(matrix, row, column, dMat, row, 1);
    maxLength = max_length_of_number(matrix, row, 1);

    if(is_fractional_matrix(matrix)) {
        matrix++;
        for(i=0 ; i<row ; i++){
            // to fit equal sign
            if(i == row/2)
                write << "  =>  | " << variables[i] << " |  =  |";
            else
                write << "      | " << variables[i] << " |     |";

            if(*(matrix+i*2+1) == 1)
                write << setw(maxLength) << *(matrix+i*2) << "       |" << endl;
            else
                write << setw(maxLength) << *(matrix+i*2) << "/" << *(matrix+i*2+1) << " |" << endl;
        }
        matrix--;
    }

    else {
        for(i=0 ; i<row ; i++){
            for(i=0 ; i<row ; i++){
                // to fit equal sign
                if(i == row/2)
                    write << "  =>  | " << variables[i] << " |  =  | " << setw(maxLength) << *(matrix+i) << " |" << endl;
                else
                    write << "      | " << variables[i] << " |     | " << setw(maxLength) << *(matrix+i) << " |" << endl;
            }
        }
    }



/* for
    x = 5
    y = 10
    z = 2
*/
    write << endl << "So," << endl;
    if(is_fractional_matrix(matrix)) {
        matrix++;
        for(i=0 ; i<row ; i++) {
            if(*(matrix+i*2+1) == 1)
                write << "\t   " << variables[i] << " = " << *(matrix+i*2) << endl;
            else
                write << "\t   " << variables[i] << " = " << *(matrix+i*2) << "/" << *(matrix+i*2+1) << endl;
        }

    }

    else {
        for(i=0 ; i<row ; i++)
            write << "\t   " << variables[i] << " = " << *(matrix+i) << endl;
    }


    write.close();
}


void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName) {
    int row, column, *coefficientMatrix, *matrix, *dMat, *mat;
    char *variables;


    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);

    write_introduction_part("Inverse Matrix", equationFileName, solutionFileName, coefficientMatrix, row, column, dMat, variables);
    write_2nd_part_in_SolutionByInvers(solutionFileName, coefficientMatrix, row, column, dMat, variables);
    write_3rd_part_in_SolutionByInvers(solutionFileName, coefficientMatrix, row, column, dMat, variables);



    cout << endl << "Solution is successfully written in \"" << solutionFileName << "\"" << endl;
}

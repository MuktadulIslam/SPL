#include<bits/stdc++.h>
#include "linearSystem.h"
#include "matrix.h"

using namespace std;

void write_in_file_GaussianElimination(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[]) {
    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }


    int i, j, temp1, temp2, maxLength;

    temp1 = max_length_of_number(coefficientMatrix, row, column);
    temp2 = max_length_of_number(dMat, row, 1);
    if(temp1 > temp2)
        maxLength = temp1;
    else
        maxLength = temp2;

    write << endl;
    for(i=0 ; i<row ; i++){
        // to fit equal sign
        if(i == row/2)
            write << "  =>  | ";
        else
            write << "      | ";


        for(j=0 ; j<column ; j++)
            write << setw(maxLength) << *(coefficientMatrix + i*column + j) << "  ";

        write << "| " << setw(maxLength) << dMat[i] << " |" << endl;
    }

    write.close();
}


void solution_by_GaussianElimination(char *equationFileName, char *solutionFileName) {
    int row, column, *coefficientMatrix, *matrix, *dMat, *mat;
    char *variables;
    ofstream write;

    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);
    write_introduction_part("Gaussian Elimination", equationFileName, solutionFileName, coefficientMatrix, row, column, dMat, variables);

    int i, j, k, multiplier1, multiplier2, LCM, *temp1, *temp2;

    write_in_file_GaussianElimination(solutionFileName, coefficientMatrix, row, column, dMat);

    for(i=0 ; i<row-1 ; i++) {
        write.open(solutionFileName, ios_base::app);

        for(j=i+1 ; j<row ; j++) {
            temp1 = (coefficientMatrix + i*column + i);
            temp2 = (coefficientMatrix + j*column + i);

            LCM = lcm(*temp1 , *temp2);
            multiplier1 = LCM/ abs(*temp1);
            multiplier2 = LCM/ abs(*temp2);

            if((*temp1) * (*temp2) > 0) {    // if both are in same sign
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + i*column + k;
                    temp2 = coefficientMatrix + j*column + k;

                    *temp2 = (*temp2 * multiplier2) - (*temp1 * multiplier1);
                }
                *(dMat+j) = *(dMat+j)*multiplier2 - *(dMat+i)*multiplier1;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier2 << "  " << "r" << i+1 << "*" << multiplier1 << " ]";
            }

            else {
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + i*column + k;
                    temp2 = coefficientMatrix + j*column + k;

                    *temp2 = (*temp2 * multiplier2) + (*temp1 * multiplier1);
                }
                *(dMat+j) = *(dMat+j)*multiplier2 + *(dMat+i)*multiplier1;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier2 << " + " << "r" << i+1 << "*" << multiplier1 << " ]";
            }
        }
        write.close();

        write_in_file_GaussianElimination(solutionFileName, coefficientMatrix, row, column, dMat);
    }
}

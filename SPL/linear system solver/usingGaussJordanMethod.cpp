#include<bits/stdc++.h>
#include "linearSystem.h"
#include "matrix.h"

using namespace std;

void makeUpperTriangleMatrix(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[]) {
    int i, j, k, l, GCD, *temp1, *temp2, t1, t2, multiplier1, multiplier2, maxLength;

    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }



/*
    |   1     3     2  |    5 |         |  90     0     0  |   20 |
    |   0   -90     0  | -170 |    to   |   0   -90     0  | -170 |
    |   0     0   -18  |    8 |         |   0     0   -18  |    8 |
*/
    for(i=row-1 ; i>0; i--) {
        for(j=i-1 ; j>=0 ; j--) {
            temp1 = (coefficientMatrix + j*column + i);
            temp2 = (coefficientMatrix + i*column + i);

            GCD = gcd(*temp1 , *temp2);
            multiplier1 = abs(*temp2 / GCD);
            multiplier2 = abs(*temp1 / GCD);

            if(*temp1>0 && *temp2>0  ||  *temp1<0 && *temp2<0 ) {    // if both are in same sign
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + j*column + k;
                    temp2 = coefficientMatrix + i*column + k;

                    *temp1 = (*temp1 * multiplier1) - (*temp2 * multiplier2);
                }
                *(dMat+j) = *(dMat+j)*multiplier1 - *(dMat+i)*multiplier2;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier1 << " - " << "r" << i+1 << "*" << multiplier2 << " ]";
            }

            else {
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + j*column + k;
                    temp2 = coefficientMatrix + i*column + k;

                    *temp1 = (*temp1 * multiplier1) + (*temp2 * multiplier2);
                }
                *(dMat+j) = *(dMat+j)*multiplier1 + *(dMat+i)*multiplier2;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier1 << " + " << "r" << i+1 << "*" << multiplier2 << " ]";
            }

            t1 = rowElementSmaller(coefficientMatrix, row, column, dMat, j);
            if(t1 != 1){
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "/" << t1 << " ]";
            }


            /* Writhing matrix in file */
            t1 = max_length_of_number(coefficientMatrix, row, column);
            t2 = max_length_of_number(dMat, row, 1);
            if(t1 > t2)
                maxLength = t1;
            else
                maxLength = t2;

            write << endl;
            for(k=0 ; k<row ; k++){
                // to fit equal sign
                if(k == row/2)
                    write << "  =>  |";
                else
                    write << "      |";


                for(l=0 ; l<column ; l++)
                    write << setw(maxLength) << *(coefficientMatrix + k*column + l) << "  ";

                write << "| " << setw(maxLength) << dMat[k] << " |" << endl;
            }
        }
    }
    write.close();
}


void writeValue_in_file_GaussJordanMethod(string solutionFileName,int *coefficientMatrix, int row, int column, int dMat[], char variables[]) {
    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }

    write << endl << endl << "So now we get, \n";
    for(int GCD, temp, i=0 ; i<row ; i++){
        temp = *(coefficientMatrix + i*column + i);

        if(temp % dMat[i] == 0) {
            write << "\t\t" << variables[i] << " = " << temp / dMat[i] << endl << endl;
        }
        else {
            GCD = gcd(temp, dMat[i]);
            if(temp < 0) {
                write << "\t\t" << variables[i] << " = " << -dMat[i]/GCD << "/" << -temp / GCD << endl << endl;
            }
            else {
                write << "\t\t" << variables[i] << " = " << dMat[i]/GCD << "/" << temp / GCD << endl << endl;
            }
        }
    }
    write.close();
}



void solution_by_GaussJordanMethod(char *equationFileName, char *solutionFileName) {
    int row, column, *coefficientMatrix, *matrix, *dMat, *mat;
    char *variables;
    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);

    write_introduction_part("Gauss Jordan Method", equationFileName, solutionFileName, coefficientMatrix, row, column, dMat, variables);
    makeLowerTriangleMatrix(solutionFileName, coefficientMatrix, row, column, dMat);
    makeUpperTriangleMatrix(solutionFileName, coefficientMatrix, row, column, dMat);
    writeValue_in_file_GaussJordanMethod(solutionFileName, coefficientMatrix, row, column, dMat, variables);

    cout << endl << "Solution of \" " << equationFileName  << " \" linear system is successfully written in \""
    << solutionFileName << "\" by using Gauss Jordan Method rules" << endl;
}


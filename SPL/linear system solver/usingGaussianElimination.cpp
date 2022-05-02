#include<bits/stdc++.h>
#include "linearSystem.h"
#include "matrix.h"

using namespace std;

void writeValue_in_file_GaussianElimination(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[], char variables[]) {
    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }

    write << endl << endl << "So now we get, \n";
    int i, j;
    long long GCD, divisor[row], dividend[row];
    for(i=row-1 ; i>=0 ; --i) {
        dividend[i] = 0;
        divisor[i] = 1;

        /* for addition
            if 2x + 3y - 4z = 3.....y=3/11, z= 5/7... then
                dividend[x] = 3(3/11) - 4(5/7)
                divisor[x] = 11*7
        */
        for(j=row-1 ; j>i ; --j){
            dividend[i] = (dividend[i]*divisor[j]) + ((long long)*(coefficientMatrix + i*column + j) * dividend[j] * divisor[i]);
            divisor[i] = divisor[i] * divisor[j];
            if(dividend[i] != 0) {
                GCD = gcd(dividend[i], divisor[i]);
                dividend[i] /= GCD;
                divisor[i] /= GCD;
            }
            else {
                divisor[i] = 1;
            }

        }

        /* for finding the value of the variable
            if 2x + 3y - 4z = 3.....y=3/11, z= 5/7... then
                x = (3 - dividend[x]/divisor[x])/2
        */
        dividend[i] = ((long long)dMat[i]*divisor[i]) - dividend[i];
        divisor[i]  *=   *(coefficientMatrix + i*column + i);


        if(dividend[i] != 0) {
            if(divisor[i] < 0){
                divisor[i] = - divisor[i];
                dividend[i] = - dividend[i];
            }

            GCD = gcd(dividend[i], divisor[i]);
            dividend[i] /= GCD;
            divisor[i] /= GCD;
        }
        else {
            divisor[i] = 1;
        }
    }



    for(i=0 ; i<row ; i++){
        if(divisor[i] == 1) {
            write << "\t\t" << variables[i] << " = " << dividend[i] << endl << endl;
        }
        else {
            if(divisor[i] < 0) {
                write << "\t\t" << variables[i] << " = " << -dividend[i] << "/" << -divisor[i] << endl << endl;
            }
            else {
                write << "\t\t" << variables[i] << " = " << dividend[i] << "/" << divisor[i] << endl << endl;
            }
        }
    }
    write.close();
}

void solution_by_GaussianElimination(char *equationFileName, char *solutionFileName) {
    int row, column, *coefficientMatrix, *matrix, *dMat, *mat;
    char *variables;
    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);

    write_introduction_part("Gaussian Elimination", equationFileName, solutionFileName, coefficientMatrix, row, column, dMat, variables);
    makeLowerTriangleMatrix(solutionFileName, coefficientMatrix, row, column, dMat);
    writeValue_in_file_GaussianElimination(solutionFileName, coefficientMatrix, row, column, dMat, variables);

    cout << endl << "Solution of \" " << equationFileName  << " \" linear system is successfully written in \""
    << solutionFileName << "\" by using Gaussian Elimination rules" << endl;
}


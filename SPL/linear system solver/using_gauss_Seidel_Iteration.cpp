#include<bits/stdc++.h>
#include "linearSystem.h"
using namespace std;

void gauss_seidel_iteration_method(char *equationFileName) {
    int i, j, iter = 0;
    int row, column, *coefficientMatrix, *dMat, *mat;
    char *variables;

    // Converting the linera equation to matrix form
    input_equation_from_file(equationFileName, &row, &column, &coefficientMatrix, &dMat, &variables);



    double newValue[row], oldValue, sum, Max, difference;
    for(i=0 ; i<row ; i++)
        newValue[i] = (double)*(dMat+i) / (double)*(coefficientMatrix + i*column + i);


    for(i=0 ; i<row ; i++) {
        sum = 0;
        for(j=0 ; j<row ; j++){
            if(j == i)
                continue;

            sum += (double) abs(*(coefficientMatrix + i*column + j));
        }
        if((double)abs(*(coefficientMatrix + i*column + i)) < sum) {
            cout << "Coefficient Matrix is not Diagonally dominant.... Gauss-Seidel Iteration Method can't be applied on this linear system." << endl;
            return;
        }

    }

    while(true) {
        iter++;
        sum = 0;
        Max = 0;
        for(i=0 ; i<row ; i++) {
            sum = 0;
            for(j=0 ; j<row ; j++) {
                if(j == i) continue;
                sum += (double)*(coefficientMatrix + i*column + j) * newValue[j];
            }

            oldValue = newValue[i];
            newValue[i] = ((double)dMat[i] - sum) / (double)*(coefficientMatrix + i*column + i);

            difference = fabs(newValue[i] - oldValue);
            if(Max < difference)
                Max = difference;
        }
        if(Max < EPSILON)   // EPSILON is defined in "linearSystem.h" header file
            break;

    }

    // Output
    for(i=0 ; i<row ; i++)
        cout << *(variables + i) << " = " << newValue[i] << endl;
    cout << "Number of interation = " << iter << endl;
}



#include<bits/stdc++.h>
#include "matrix.h"

using namespace std;

int get_variable_index(char variables[], char variable) {
    for(int i=0 ; variables[i] ; i++) {
        if(variables[i] == variable)
            return i;
    }
    return -1;
}


void input_fequation_from_console(int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat) {

    char *p, str[200], *variables, sign = '+', temp1[10], temp2[10];
    int i, j, k, l, *matrix, *dMat;
    bool gotVariable, gotDivident, gotDivisor, gotEqualSign, flag;
    int noOfVariable, noOfCoefficient;

    cout << "Enter the number of linear equation:  ";
    cin >> *row;
    *column = *row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer



    // Initializing memory for 3 types of matrix
    matrix = (int*) malloc((*row) * (*row) * sizeof(int) * 2);
    dMat = (int*) malloc((*row) * sizeof(int));
    variables = (char*) malloc(*row);

    *coefficientMat = matrix;
    *Dmatrix = dMat;
    *variablesMat = variables;




    cout << "Now enter " << *row << " linear equation: \n";
    for(i=0 ; i < *row ; i++) {
        gotVariable = false;
        gotDivident = false;
        gotDivisor = false;
        gotEqualSign = false;
        noOfCoefficient = 0;
        noOfVariable = 0;
        sign = '+';

        cin.getline(str,200);

        for(p=str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '=') {
                gotEqualSign = true;
                sign = '+';
            }
            else if(*p == '+' || *p == '-') {
                sign = *p;
                gotDivident = false;
            }

            else if(*p >= '0' && *p <= '9') {

                if(gotEqualSign) {      //  5x + 6y  -2z = m,,,,,,,,to get the value of 'm'
                    p = getNumber(p, sign, dMat);
                    dMat++;

                    p++;
                    flag = true;
                    while(*p) {
                        if(*p >= '0' && *p <= '9'){
                            getNumber(p, sign, dMat);
                            dMat++;
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        *dMat++ = 1;

                    break;      // No need to continue the loop, because the equation is over
                }
                else if(!gotDivident  && !gotVariable && !gotDivisor) {
                    // geting divident of a coefficient
                    p = getNumber(p, sign, matrix);
                    matrix++;
                    gotDivident = true;
                    noOfCoefficient++;
                }
                else if(gotDivident &&  !gotDivisor && !gotVariable){
                    // geting divisor of a coefficient
                    p = getNumber(p, '+' , matrix);
                    matrix++;
                    gotDivisor = true;
                }
            }

            else if(*p >= 'a' && *p <= 'z'   ||   *p >= 'A' && *p <= 'Z') {

                if(!gotDivident) {      // x + 2y = 1,,,,,,coefficient of 'x' will be 1/1
                    if(sign == '+')
                        *matrix++ = 1;
                    else
                       *matrix++ = -1;

                    *matrix++ = 1;

                }
                else if(!gotDivisor)    // 2x + 3/2y = 5,,,,,,,coefficient of 'x' will be 2/1;
                    *matrix++ = 1;

                if(i == 0) {    // i=0,,,,,,because no need to get the variables again
                   *variables++ = *p;
                }
                gotDivident = false;
                gotDivisor = false;
                noOfVariable++;
            }
        }
    }
}



void input_fequation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat) {

    char *p, str[200], *variables, sign = '+', temp1[10], temp2[10];
    int i, j, k, l, *matrix, *dMat;
    bool gotVariable, gotDivident, gotDivisor, gotEqualSign, flag;
    int noOfVariable, noOfCoefficient;

    freopen(fileName, "r" , stdin);
    cin >> *row;
    *column = *row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer



    // Initializing memory for 3 types of matrix
    matrix = (int*) malloc((*row) * (*row) * sizeof(int) * 2);
    dMat = (int*) malloc((*row) * sizeof(int));
    variables = (char*) malloc(*row);

    *coefficientMat = matrix;
    *Dmatrix = dMat;
    *variablesMat = variables;



    for(i=0 ; i < *row ; i++) {
        gotVariable = false;
        gotDivident = false;
        gotDivisor = false;
        gotEqualSign = false;
        noOfCoefficient = 0;
        noOfVariable = 0;
        sign = '+';

        cin.getline(str,200);

        for(p=str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '=') {
                gotEqualSign = true;
                sign = '+';
            }
            else if(*p == '+' || *p == '-') {
                sign = *p;
                gotDivident = false;
            }

            else if(*p >= '0' && *p <= '9') {

                if(gotEqualSign) {      //  5x + 6y  -2z = m,,,,,,,,to get the value of 'm'
                    p = getNumber(p, sign, dMat);
                    dMat++;

                    p++;
                    flag = true;
                    while(*p) {
                        if(*p >= '0' && *p <= '9'){
                            getNumber(p, sign, dMat);
                            dMat++;
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        *dMat++ = 1;

                    break;      // No need to continue the loop, because the equation is over
                }
                else if(!gotDivident  && !gotVariable && !gotDivisor) {
                    // geting divident of a coefficient
                    p = getNumber(p, sign, matrix);
                    matrix++;
                    gotDivident = true;
                    noOfCoefficient++;
                }
                else if(gotDivident &&  !gotDivisor && !gotVariable){
                    // geting divisor of a coefficient
                    p = getNumber(p, '+' , matrix);
                    matrix++;
                    gotDivisor = true;
                }
            }

            else if(*p >= 'a' && *p <= 'z'   ||   *p >= 'A' && *p <= 'Z') {

                if(!gotDivident) {      // x + 2y = 1,,,,,,coefficient of 'x' will be 1/1
                    if(sign == '+')
                        *matrix++ = 1;
                    else
                       *matrix++ = -1;

                    *matrix++ = 1;

                }
                else if(!gotDivisor)    // 2x + 3/2y = 5,,,,,,,coefficient of 'x' will be 2/1;
                    *matrix++ = 1;

                if(i == 0) {    // i=0,,,,,,because no need to get the variables again
                   *variables++ = *p;
                }
                gotDivident = false;
                gotDivisor = false;
                noOfVariable++;
            }
        }
    }
}



void input_equation_from_file(char *fileName, int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat) {
    char *p, str[200], *variables, sign = '+', temp1[10], temp2[10];
    int i, j, k, l, *matrix, *dMat, coefficient;
    bool gotVariable, gotCoefficient, gotEqualSign, flag;

    freopen(fileName, "r" , stdin);
    cin >> *row;
    *column = *row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer



    // Initializing memory for 3 types of matrix
    matrix = (int*) malloc((*row) * (*row) * sizeof(int));
    dMat = (int*) malloc((*row) * sizeof(int));
    variables = (char*) malloc(*row);

    for(char *temp = variables, i=0 ; i<*row ; i++)
        *temp++ = 0;

    int tempMatrix[*row][*column];
    for(i=0 ; i<*row ; i++)
        for(j=0 ; j<*column ; j++)
            tempMatrix[i][j] = 0;


    *coefficientMat = matrix;
    *Dmatrix = dMat;
    *variablesMat = variables;



    for(i=0 ; i < *row ; i++) {
        gotVariable = true;
        gotCoefficient = false;
        gotEqualSign = false;
        sign = '+';
        coefficient = 0;

        cin.getline(str,200);

        for(p=str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '=') {
                gotEqualSign = true;
                sign = '+';
            }
            else if(*p == '+' || *p == '-') {
                sign = *p;
                gotCoefficient = false;
            }

            else if(*p >= '0' && *p <= '9') {

                if(gotEqualSign) {
                    p = getNumber(p, sign, dMat);
                    dMat++;

                    break;      // No need to continue the loop, because the equation is over
                }
                else if(!gotCoefficient  && gotVariable) {
                    p = getNumber(p, sign, &coefficient);
                    gotCoefficient = true;
                }
            }

            else if(*p >= 'a' && *p <= 'z'   ||   *p >= 'A' && *p <= 'Z'){

                if(i == 0) {    // i=0,,,,,,because no need to get the variables again
                   *variables++ = *p;
                }

                if(!gotCoefficient) {      // x + 2y = 1,,,,,,coefficient of 'x' will be 1
                    if(sign == '+')
                        tempMatrix[i][get_variable_index(*variablesMat, *p)]= 1;

                    else
                        tempMatrix[i][get_variable_index(*variablesMat, *p)]= -1;
                }
                else{
                    tempMatrix[i][get_variable_index(*variablesMat, *p)] = coefficient;
                }

                gotCoefficient = false;
                gotVariable = true;
            }
        }
    }

    for(i=0 ; i<*row ; i++) {
        for(j=0 ; j<*column ; j++) {
            *matrix++ = tempMatrix[i][j];
        }
    }
}


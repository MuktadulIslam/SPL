/*
#include<bits/stdc++.h>
using namespace std;

int* matrix_input(int *row, int *column);
char * getNumber(char *p, char sign, int *matrix);

int* input_equation_from_console(int *row, int *column, int *coefficientMat, int *Dmatrix, int *variablesMat) {
    char *p, str[200], sign = '+', temp1[10], temp2[10];
    int i, j, k, l, *matrix, variablesIdx = 0 ;

    cout << "Enter the number of linear equation:  ";
    cin >> *row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

    matrix = (int*) malloc((*row) * (*column) * sizeof(int) * 2);
    var
    coefficientMat = matrix;

    char variables[*row];
    bool gotVariable, gotDivident, gotDivisor;

    cout << "Now enter " << *row << " linear equation: \n";
    for(i=0 ; i < *row ; i++) {
        cin.getline(str,200);
        gotVariable = false;
        gotDivident = false;
        gotDivisor = false;

        for(p=str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '+' || *p == '-') {
                sign = *p;
                gotDivident = false;
            }

            else if(*p >= '0' && *p <= '9') {

                if(variablesIdx == *row) {      //  5x + 6y  -2z = m,,,,,,,,to get the value of 'm'

                }
                else if(!gotDivident  && !gotVariable && !gotDivisor) {
                    // geting divident of a coefficient
                    p = getNumber(p, sign, matrix);
                    gotDivident = true;
                }
                else if(gotDivident &&  !gotDivisor && !gotVariable){
                    // geting divisor of a coefficient
                    p = getNumber(p, '+' , matrix);
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

                if(variablesIdx < *row  && i == 0) {
                   variables[variablesIdx++] = *p;
                   gotDivident = false;
                   gotDivisor = false;
                }
            }
        }
    }

    for(i=0 ; i < *row ; i++) cout << variables[i] << "    ";

    return matrix;
}

char * getNumber(char *p, char sign, int *matrix) {
    int i, j, k;
    char temp1[10], temp2[10];

    k = 0;
    while(*p >= '0' && *p <= '9') {
        temp1[k++] = *p;
        p++;
    }

    for(j = 0 ; k>=0 ; )
        temp2[j++] = temp1[--k];

    temp2[j] = '\0';

    for(j=0 , k=0 ; temp2[j] ; j++) {
        k = k + (temp2[j] - '0')*pow(10,j);
    }

    if(sign == '+')
        *matrix++ = k;
    else
        *matrix++ = -k;

    return --p;
}

*/

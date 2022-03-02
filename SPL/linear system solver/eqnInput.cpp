#include<bits/stdc++.h>
using namespace std;

int* matrix_input(int *row, int *column);
char * getNumber(char *p, char sign, int *matrix);



void input_equation_from_console(int *row, int *column, int **coefficientMat, int **Dmatrix, char **variablesMat) {

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
        *matrix = k;
    else
        *matrix = -k;

    return --p;
}


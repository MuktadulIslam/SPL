#include<bits/stdc++.h>
#include "matrix.h"
#include "normal_matrix.h"

using namespace std;

int * input_matrix_from_file(char *fileName, int *row, int *column) {
    int i, j, *matrix, *temp, Count;
    char str[200], *p, sign;
    bool gotDivident, gotdivisor, gotSlash;

    freopen(fileName, "r" , stdin);
    cin >> *row >> *column;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

    matrix = (int*) malloc(((*row) * (*column)  * 2 + 1)*sizeof(int));
    temp = matrix;
    *matrix++ = INT_MAX;


    for(i=0 ; i < *row ; i++) {
        gotDivident = false;
        gotSlash = false;
        gotdivisor = true;
        Count = 0;
        sign = '+';

        cin.getline(str,200);

        for(p = str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '/') gotSlash = true;

            else if(*p == '+' || *p == '-') {
                sign = *p;
                if (!gotdivisor) {
                    *matrix++ = 1;
                    Count++;
                }
                gotDivident = false;
            }
            else if(*p >= '0' && *p <= '9') {
                if(!gotDivident) {
                    p = getNumber(p, sign, matrix);    // reading divident
                    sign = '+';
                    matrix++;
                    Count++;
                    gotDivident = true;
                    gotdivisor = false;
                }
                else if(gotSlash && gotDivident) {
                    sign = '+';
                    p = getNumber(p, sign, matrix);    // reading divisor
                    matrix++;
                    Count++;
                    gotSlash = false;
                    gotDivident = false;
                    gotdivisor = true;
                }
                else if (!gotSlash && gotDivident) {
                    *matrix++ = 1;
                    Count++;

                    gotDivident = false;
                    gotdivisor = true;
                    p--;
                }
            }
        }
        if(Count < *row * 2) *matrix++ = 1;
    }

    return matrix_memory_optimization(temp, *row, *column);
}




int * input_matrix_from_console(int *row, int *column) {
    int i, j, *matrix, *temp, Count;
    char str[200], *p, sign;
    bool gotDivident, gotdivisor, gotSlash;

    cout << "Enter the number of row and column:  ";
    cin >> *row >> *column;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer

    matrix = matrix = (int*) malloc(((*row) * (*column)  * 2 + 1)*sizeof(int));
    temp = matrix;
    *matrix++ = INT_MAX;


    cout << "Now enter the  " << *row << 'X' << *column << "  Matrix:" << endl;
    for(i=0 ; i < *row ; i++) {
        gotDivident = false;
        gotSlash = false;
        gotdivisor = true;
        Count = 0;
        sign = '+';

        cin.getline(str,200);

        for(p = str ; *p ; p++) {
            if(*p == ' ') continue;
            else if(*p == '/') gotSlash = true;

            else if(*p == '+' || *p == '-') {
                sign = *p;
                if (!gotdivisor) {
                    *matrix++ = 1;
                    Count++;
                }
                gotDivident = false;
            }
            else if(*p >= '0' && *p <= '9') {
                if(!gotDivident) {
                    p = getNumber(p, sign, matrix);    // reading divident
                    sign = '+';
                    matrix++;
                    Count++;
                    gotDivident = true;
                    gotdivisor = false;
                }
                else if(gotSlash && gotDivident) {
                    sign = '+';
                    p = getNumber(p, sign, matrix);    // reading divisor
                    matrix++;
                    Count++;
                    gotSlash = false;
                    gotDivident = false;
                    gotdivisor = true;
                }
                else if (!gotSlash && gotDivident) {
                    *matrix++ = 1;
                    Count++;

                    gotDivident = false;
                    gotdivisor = true;
                    p--;
                }
            }
        }
        if(Count < *row * 2) *matrix++ = 1;
    }

    return matrix_memory_optimization(temp, *row, *column);
}



void print_matrix(int *matrix, int row, int column) {
    if(matrix == NULL) {
        cout << "The matrix is empty!!!!!" << endl;
        return;
    }

    else {
        // Checking it's fmatrix or normal matrix;
        if(*matrix == INT_MAX) {

            matrix++;       // first index hold INT_MAX as the identity

            int i, j, t, t1, t2, a, b;
            for(i=0 ; i<row ; i++){
                for(j=0 ; j<column ; j++) {
                    a = *(matrix + i*column*2 + j*2);
                    b = *(matrix + i*column*2 + j*2 + 1);

                    if(a%b == 0)     // if divident % divisor == 0
                        cout << a/b << "    ";
                    else if(b%a == 0) {     // if divisor % divident == 0
                        if(b/a >= 0)
                            cout << "1/" << b/a << "   ";
                        else
                            cout << "-1/" << -b/a << "   ";
                    }
                    else {
                        t = lcm(a , b);
                        t1 = t/b;
                        t2 = t/a;

                        if(t2 >= 0)
                            cout << t1 << '/' << t2 << "   ";
                        else if(t2<0)
                            cout << -t1 << '/' << -t2 << "   ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        else {
            print_normal_matrix(matrix, row, column);
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int * key(int *row, int *column) {
    int *matrix;
    *row = 3;
    *column = 3;
    matrix = (int*) malloc((*row) * (*column) * sizeof(int));

    *matrix = -61;
    *(matrix+1) = 58;
    *(matrix+2) = 18;

    *(matrix+3) = -19;
    *(matrix+4) = 5;
    *(matrix+5) = 9;

    *(matrix+6) = -10;
    *(matrix+7) = 89;
    *(matrix+8) = -10;


    return matrix;
}







//int * key(int *row, int *column) {
//    int *matrix;
//    *row = 4;
//    *column = 2;
//    matrix = (int*) malloc((*row) * (*column) * sizeof(int));
//
//    *matrix = 61;
//    *(matrix+1) = 58;
//    *(matrix+2) = 18;
//    *(matrix+3) = 19;
//
//
//    *(matrix+4) = 95;
//    *(matrix+5) = 90;
//    *(matrix+6) = 10;
//    *(matrix+7) = 89;
//
//    return matrix;
//}



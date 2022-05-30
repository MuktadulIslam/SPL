#include <bits/stdc++.h>
using namespace std;

int * key(int *row, int *column) {
    int *matrix;
    *row = 3;
    *column = 3;
    matrix = (int*) malloc((*row) * (*column) * sizeof(int));

    *matrix = -1;
    *(matrix+1) = 8;
    *(matrix+2) = 1;

    *(matrix+3) = 2;
    *(matrix+4) = 5;
    *(matrix+5) = 1;

    *(matrix+6) = -4;
    *(matrix+7) = 3;
    *(matrix+8) = 5;


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



#include<bits/stdc++.h>
#include "matrix.h"
#include "linearSystem.h"
#include "normal_matrix.h"
#include "cryptography.h"

using namespace std;

int main(void) {
    int i,j,k = 0,row, column, *matrix1, det[2], *matrix2, *matrix3, *matrix4;

//    solution_by_GaussJordanMethod("equation.txt", "solution3.txt");
    solution_by_GaussianElimination("equation.txt", "solution4.txt");
//    solution_by_inverseMatrix("equation2.txt", "solution2.txt");
//    solution_by_cramersRules("equation.txt", "solution1.txt");


//    encryption("plaintext.txt", "encryptedText.bin");
//    decryption("encryptedText.bin", "decryptedText.txt");

}

#include<bits/stdc++.h>
#include "matrix.h"
#include "cryptography.h"

using namespace std;

void encryption(string plaintextFile, string encryptedFile) {
    ofstream write;
    ifstream read ;
    string tempString = "";
    char str[5000];

// Opening files
        write.open(encryptedFile, ios::binary | ios::out);
        if(!write.is_open()) {
            cout << "Failed to open " << encryptedFile << " file!!!!!";
            exit(1);
        }
        read.open(plaintextFile);
        if(!read.is_open()) {
            cout << "Failed to open " << plaintextFile << " file!!!!!";
            exit(1);
        }



// for reading the whole text in a string
    while(!read.eof()) {
        read.getline(str, 5000);
        tempString = tempString + str + "\n";
    }


// this section for Encryption
    cout << tempString.length() << endl;
    char text[tempString.length()], *plaintext;
    strcpy(text, tempString.c_str());
    plaintext = text;

    int row, column, *matrix1, *matrix2, *KEY;
    KEY = key(&row, &column);
    int mat[row][column];

    while(*plaintext != '\0'){
        plaintext = stringToMatrix(&mat[0][0], row, column, plaintext);
        matrix1 = matrix_subtraction(&mat[0][0], row, column, KEY, row, column);
        matrix2 = matrix_transpose(matrix1, row, column);

        tempString = matrixToString(matrix2, column, row);
        strcpy(str, tempString.c_str());
        write.write(str, row*column);

        free(matrix1);
        free(matrix2);
    }



    write.close();
    read.close();
}

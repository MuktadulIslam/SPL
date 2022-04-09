#include<bits/stdc++.h>
#include "matrix.h"
#include "cryptography.h"

using namespace std;

void decryption(string encryptedFile, string decryptedFile) {
    ofstream write;
    ifstream read ;
    string tempString = "";
    char str[5000];

// Opening files
        read.open(encryptedFile, ios::binary | ios::in);
        if(!read.is_open()) {
            cout << "Failed to open " << encryptedFile << " file!!!!!";
            exit(1);
        }
    write.open(decryptedFile);
        if(!write.is_open()) {
            cout << "Failed to open " << decryptedFile << " file!!!!!";
            exit(1);
        }



// for reading the whole text in a string
    while(!read.eof()) {
        read.read((char *) str, 5000);
        tempString = tempString + str;
    }


// this section for Encryption
    cout << endl << tempString.length() << endl << endl;
    char text[tempString.length()+1], *encryptedText;
    strcpy(text, tempString.c_str());
    encryptedText = text;

    int row, column, *matrix1, *matrix2, *KEY;
    KEY = key(&row, &column);
    int mat[column][row];

    while(*encryptedText) {
        encryptedText = stringToMatrix(&mat[0][0], column, row, encryptedText);
        matrix1 = matrix_transpose(&mat[0][0], column, row);
        matrix2 = matrix_addition(matrix1, row, column, KEY, row, column);

        write << matrixToString(matrix2, row, column);
        free(matrix1);
        free(matrix2);
    }



    write.close();
    read.close();
}

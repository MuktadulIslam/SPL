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
    char text[tempString.length()], *plaintext;
    strcpy(text, tempString.c_str());
    plaintext = text;

    int row, column, *matrix1, *KEY;
    short *matrix2;
    KEY = key(&row, &column);
    int mat[column][row];

    while(*plaintext != '\0'){
        plaintext = stringToMatrix(&mat[0][0], column, row, plaintext);

        matrix1 = matrix_multiplication(KEY, row, column, &mat[0][0], column, row);
        write.write((char *) matrix1, sizeof(int)*row*column);
    }



    write.close();
    read.close();

    cout << "Successfully encrypted!!!!" << ".......Encrypted in \"" << encryptedFile << "\" file \n";
}

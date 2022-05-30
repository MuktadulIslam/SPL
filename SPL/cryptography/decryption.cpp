#include<bits/stdc++.h>
#include "matrix.h"
#include "cryptography.h"

using namespace std;

void decryption(string encryptedFile, string decryptedFile) {
    ofstream write;
    ifstream read ;

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


// this section for Decryption
    int i, j, row, column, *matrix1, *matrix2, *KEY;
    KEY = key(&row, &column);
    int mat[column][row];
    int temp;

    while(!read.eof()) {
        for(i=0 ; i<column && !read.eof() ; i++) {
            for(j=0 ; j<row && !read.eof() ; j++) {
//                read.read((char *) &temp, sizeof(short));
                read.read((char *) &temp, sizeof(int));

                mat[i][j] = temp;
            }

            // if EOF occur befor completly mat array
            while(j<row)
                mat[i][j++] = 0;
        }
        // Again
        while(i<column) {
            for(j=0 ; j<row ; j++)
                mat[i][j] = 0;

            i++;
        }

//        removing some unwanted byte which created by file writer
        bool flag = true;
        for(int *p = &mat[0][1], i=0 ; i<column ; i++) {
            for(j =0 ; j<row ; j++) {
                if(j==0 && i == 0)
                    continue;
                else if(mat[i][j] != 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) break;

        matrix1 = matrix_inverse(KEY, row, column);
        matrix2 = matrix_multiplication(matrix1, row, column, &mat[0][0], column, row);

        write << matrixToString(matrix2, row, column);
        free(matrix1);
        free(matrix2);
    }

    write.close();
    read.close();

    cout << "Successfully decrypted!!!!" << ".......Decrypted in \"" << decryptedFile  << "\" file \n";
}

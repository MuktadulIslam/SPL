#include<bits/stdc++.h>
#include "linearSystem.h"
#include "matrix.h"

using namespace std;

int rowElementSmaller(int *coefficientMatrix, int row, int column, int dMat[], int rowNo) {
    /* for
        | 4 6 | 2|      | 2 3 | 1|
        | 3 9 | 6| to   | 3 9 | 6|
    */
    int GCD = 0;
    if(dMat[rowNo] == 0 && *(coefficientMatrix + rowNo*column) == 0)
        GCD = 1;
    else if(dMat[rowNo] == 0)
        GCD = *(coefficientMatrix + rowNo*column);
    else if(*(coefficientMatrix + rowNo*column) == 0)
        GCD = dMat[rowNo];
    else
        GCD = gcd(*(coefficientMatrix + rowNo*column), dMat[rowNo]);


    for(int *temp = coefficientMatrix + rowNo*column, j=1 ; j<column ; j++){
        temp++;
        if(*temp != 0){
            if(GCD == 1)
                GCD == abs(*temp);
            else
                GCD = gcd(*temp, GCD);
        }

    }

    if(GCD == 1) return GCD;

    for(int j=0 ; j<column ; j++) {
        *(coefficientMatrix + rowNo*column + j) /= GCD;
    }
    dMat[rowNo] /= GCD;

    return GCD;
}


void makeLowerTriangleMatrix(string solutionFileName, int *coefficientMatrix, int row, int column, int dMat[]) {
    int i, j, k, GCD, *temp1, *temp2, t1, t2, multiplier1, multiplier2, maxLength;

    // Opening the file
    ofstream write;
    write.open(solutionFileName, ios_base::app);
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }


/*
    | 1  3  2  | 5 |        |  1    3    2  |   5 |
    | 2  1  3  | 1 |   to   |  0   -5   -1  |  -9 |
    | 3  2  1  | 4 |        |  0    0  -18  |   8 |
*/
    for(i=0 ; i<row-1 ; i++) {
        for(j=i+1 ; j<row ; j++) {
            temp1 = (coefficientMatrix + i*column + i);
            temp2 = (coefficientMatrix + j*column + i);

            GCD = gcd(*temp1 , *temp2);
            multiplier1 = abs(*temp2 / GCD);
            multiplier2 = abs(*temp1 / GCD);

            if((*temp1) * (*temp2) > 0) {    // if both are in same sign
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + i*column + k;
                    temp2 = coefficientMatrix + j*column + k;

                    *temp2 = (*temp2 * multiplier2) - (*temp1 * multiplier1);
                }
                *(dMat+j) = *(dMat+j)*multiplier2 - *(dMat+i)*multiplier1;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier2 << " - " << "r" << i+1 << "*" << multiplier1 << " ]";
            }

            else {
                for(k=0 ; k<column ; k++){
                    temp1 = coefficientMatrix + i*column + k;
                    temp2 = coefficientMatrix + j*column + k;

                    *temp2 = (*temp2 * multiplier2) + (*temp1 * multiplier1);
                }
                *(dMat+j) = *(dMat+j)*multiplier2 + *(dMat+i)*multiplier1;
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "*" << multiplier2 << " + " << "r" << i+1 << "*" << multiplier1 << " ]";
            }

            t1 = rowElementSmaller(coefficientMatrix, row, column, dMat, j);
            if(t1 != 1){
                write << endl << "[r" << j+1 << "' = " << "r" << j+1 << "/" << t1 << " ]";
            }

        }


        /* Writhing matrix in file */
        t1 = max_length_of_number(coefficientMatrix, row, column);
        t2 = max_length_of_number(dMat, row, 1);
        if(t1 > t2)
            maxLength = t1;
        else
            maxLength = t2;

        write << endl;
        for(k=0 ; k<row ; k++){
            // to fit equal sign
            if(k == row/2)
                write << "  =>  |";
            else
                write << "      |";


            for(j=0 ; j<column ; j++)
                write << setw(maxLength) << *(coefficientMatrix + k*column + j) << "  ";

            write << "| " << setw(maxLength) << dMat[k] << " |" << endl;
        }
    }

    write.close();
}


void write_introduction_part(string title, string equationFileName, string solutionFileName, int *coefficientMatrix, int row, int column, int *dMat, char *variables) {
    int i, j;
    char str[200];

    //Opening the files
    ifstream read (equationFileName);
    ofstream write (solutionFileName);
    if(!read.is_open()) {
        cout << "Failed to open the \"" << equationFileName << "\" file!!!!!!" << endl;
        return;
    }
    if(!write.is_open()) {
        cout << "Failed to open the \"" << solutionFileName << "\" file!!!!!!" << endl;
        return;
    }


    /* For
    *******Solution of linear system using Cramer's law*******
        Given, the systems of linear equations:
			2x - 3y +4z = 3
			x + 4y - 5z = 0
			5x -  y +z = 5
    */
        write << "\t\t*******Solution of linear system using " << title << "*******" << endl << endl;
        read >> i;      // for input row which is not needed
        read.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer
        write << "Given, the systems of linear equations:" << endl;
        for(i=0 ; i<row ; i++) {
            read.getline(str,200);
            write << "\t\t\t" << str << endl;
        }


    /* For
        Which in matrix format is:

        |  2  -3   4  |  | x |      | 3 |
        |  1   4  -5  |  | y |  =   | 0 |
        |  5  -1   1  |  | z |      | 5 |
    */
        write << endl << "Which in matrix format is: \n";
        int maxLength = max_length_of_number(coefficientMatrix, row, column);
        for(i=0 ; i<row ; i++){
            write << "      | ";
            for(j=0 ; j<column ; j++) {
                write << setw(maxLength) << *(coefficientMatrix + i*column + j) << " ";
            }
            write << "|  ";

            write << "| " << *(variables+i) << " |";   // For print variables matrix

            if(i == row/2) {
                write << "  =   ";
                write  << "| " << setw(maxLength) << *(dMat+i) << " |";
            }
            else
                write  << "      | " << setw(maxLength) << *(dMat+i) << " |";
            write << endl;
        }

    write << endl << "Now," << endl;
    write.close();
    read.close();
}


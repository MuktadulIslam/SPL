#include<bits/stdc++.h>
#include "linearSystem.h"

using namespace std;

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

      write.close();
      read.close();
}

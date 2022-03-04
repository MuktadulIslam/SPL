#include<bits/stdc++.h>
#include "matrix.h"
#include "fmatrix.h"

using namespace std;

int * new_matrix(int *realMatrix, int row, int column, int *copyMatrix, int insertedColumnNo) {
    int i,j, *mat;
    mat = (int*) malloc(row * column * sizeof(int));

    for(i=0 ; i <row ; i++){
        for(j=0 ; j<column ; j++) {
            if(j == insertedColumnNo){
                *(mat + i*column + j) = *copyMatrix++;
                realMatrix++;
            }
            else
                *(mat + i*column + j) = *realMatrix++;
        }
    }
    return mat;

}


void solution_by_cramersRules(char *equationFileName, char *solutionFileName) {
    int i, j ,k;
    string str;
    int row, column, *matrix, *dMat, *mat;
    char *variables, *var;
    input_equation_from_file(equationFileName, &row, &column, &matrix, &dMat, &variables);


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
        Given, the systems of linear equations:
			2x - 3y +4z = 3
			x + 4y - 5z = 0
			5x -  y +z = 5
    */
    write << "\t\t*******Solution of linear system using Cramer's law*******" << endl << endl;
    read >> row;
    int del_x[row], del;
    read.ignore(numeric_limits<streamsize>::max(), '\n');        // for clear input buffer
    write << "Given, the systems of linear equations:" << endl;
    for(i=0 ; i<row ; i++) {
        getline(read, str);
        write << "\t\t\t" << str << endl;
    }


    /* For
        Which in matrix format is:
         _           _    _ _        _ _
        |  2  -3   4  |  | x |      | 3 |
        |  1   4  -5  |  | y |  =   | 0 |
        |  5  -1   1  |  | z |      | 5 |
        |_           _|  |_ _|      |_ _|
    */
    write << endl << "Which in matrix format is: \n";
        // for "_       _"
        write << " _ ";
        for(i=0 ; i<column ; i++) write << "   ";
        write << " _    _ _        _ _" << endl;

        for(i=0 ; i<row ; i++){
            write << "| ";
            for(j=0 ; j<column ; j++) {
                write << setw(2) << *(matrix + i*column + j) << "  ";
            }
            write << "|  ";

            write << "| " << *(variables+i) << " |";   // For print variables matrix

            if(i == row/2) {
                write << "  =   ";
                write  << "| " << *(dMat+i) << " |";
            }
            else
                write  << "      | " << *(dMat+i) << " |";
            write << endl;
        }

        // for "|_     _|"

        write << "|_ ";
        for(i=0 ; i<column ; i++) write << "   ";
        write << " _|  |_ _|      |_ _|" << endl << endl << endl;




        /* For
        Now,
                  | 2  -3   4  |
            DEL = | 1   4  -5  | = -8
                  | 5  -1   1  |
        */
        write << "Now," << endl;
        for(i=0 ; i<row ; i++){
            if(i == row/2)
             write << "      DEL = |";
            else
                write << "\t\t\t" << "|";

            for(j=0 ; j<column ; j++) {
                write << setw(2) << *(matrix + i*column + j) << "  ";
            }
            write << "|" ;

            if(i == row/2) {
                del = matrix_determinant(matrix, row, column);
                write << " = " << del;
            }
            write << endl;
        }
        write << endl;



        /* For
                | 2  -3   4  |
        DEL.x = | 1   4  -5  | = -3
                | 5  -1   1  |
        */
        for(k=0 ; k<row ; k++) {
            mat = new_matrix(matrix, row, column, dMat, k);
            for(i=0 ; i<row ; i++){
                if(i == row/2)
                write << "\tDEL." << *(variables + k) << " = |";
                else
                    write << "\t\t\t" << "|";

                for(j=0 ; j<column ; j++) {
                    write << setw(2) << *(mat + i*column + j) << "  ";
                }
                write << "|" ;

                if(i == row/2) {
                    del_x[k] = matrix_determinant(mat, row, column);
                    write << " = " << del_x[k];
                }
                write << endl;
            }
            write << endl;
        }



        /* For
        So now we can get the value using this method...x = (DEL.x)/DEL

		  x = (DEL.x)/DEL
		    = 69/-7
		    = -69/7
        */

        write << endl << "So now we can get the value using this method...x = (DEL.x)/DEL" << endl << endl;

        for(k=0 ; k<row ; k++) {
            write << "\t\t  " << *(variables+k) << " = (DEL." << *(variables+k) << ")/DEL" << endl;
            write << "\t\t    = " << del_x[k] << '/' << del << endl;

            if(del_x[k] % del == 0)
                write << "\t\t    = " << del_x[k]/del << endl << endl;
            else if(del % del_x[k] == 0) {
                if(del / del_x[k] > 0)
                    write << "\t\t    = 1/" << del/del_x[k] << endl << endl;
                else
                    write << "\t\t    = -1/" << -del/del_x[k] << endl << endl;
            }
            else {
                int temp = lcm(del_x[k],del);
                if(temp/del_x[k] > 0)
                    write << "\t\t    = " << temp/del << '/' << temp/del_x[k] << endl << endl;
                else
                    write << "\t\t    = " << -temp/del << '/' << -temp/del_x[k] << endl << endl;
            }
        }
}



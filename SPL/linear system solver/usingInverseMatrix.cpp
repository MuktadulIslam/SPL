#include<bits/stdc++.h>
#include "matrix.h"
#include "fmatrix.h"
#include "linearSystem.h"

using namespace std;

void solution_by_inverseMatrix(char *equationFileName, char *solutionFileName) {
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
        write << " _|  |_ _|      |_ _|" << endl << endl;



    /* For
         _ _     _           _ (-)    _ _
        | x |   |  5   1   3  |   | 1 |
     => | y | = |  8  -5   2  | X | 0 |
        | z |   | -4   2  -1  |   | 4 |
        |_ _|   |_           _|   |_ _|
	*/
        // for "_       _"
        write << "\t _ _     _";
        for(i=0 ; i<column ; i++)
            write << "   ";
        write << "  _(-)  _ _" << endl;

        for(i=0 ; i<row ; i++){
            if(i == row/2) {
                write << " => | " << *(variables+i) << " |";   // For print variables matrix
                write << " = ";
                write << "| ";
                for(j=0 ; j<column ; j++)
                    write << setw(2) << *(matrix + i*column + j) << "  ";
                write  << "| X ";
            }
            else {
                write << "\t| " << *(variables+i) << " |";   // For print variables matrix
                write << "   | ";
                for(j=0 ; j<column ; j++)
                    write << setw(2) << *(matrix + i*column + j) << "  ";
                write  << "|   ";
            }

            write << "| " << dMat[i] << " |";

            write << endl;
        }

        write << "\t|_ _|   |_";
        for(i=0 ; i<column ; i++)
            write << "   ";
        write << "  _|   |_ _|" << endl;




    /* For
              _          _      _ _
		  	| 0   1   0  |    | 9 |
		  = | 0   2   1  | X  | 6 |
		  	| 0   0   0  |    | 2 |
	        |_          _|    |_ _|

    */
        mat = matrix_inverse(matrix, row, column);
        // for "_       _"
        write << "\t         _";
        for(i=0 ; i<column ; i++)
            write << "   ";
        write << " _      _ _" << endl;

        for(i=0 ; i<row ; i++){
            write << "\t\t  ";   // For print variables matrix
            if(i == row/2) {
                write << "= ";
                write << "|";
                for(j=0 ; j<column ; j++)
                    write << setw(2) << *(mat + i*column + j) << "  ";
                write  << "| X  ";
            }
            else {
                write << "\t|";
                for(j=0 ; j<column ; j++)
                    write << setw(2) << *(mat + i*column + j) << "  ";
                write  << "|    ";
            }

            write << "| " << dMat[i] << " |";

            write << endl;
        }

        write << "\t        |_";
        for(i=0 ; i<column ; i++)
            write << "   ";
        write << " _|    |_ _|" << endl << endl;


}

#include<bits/stdc++.h>
#include"linearSystem.h"

using namespace std;

int max_length_of_number(int *matrix, int row, int column) {
    int i, j, Size, temp, Max = 0;

    if(*matrix == INT_MAX) {
        matrix++;

        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                // for divident
                Size = 0;
                temp = *(matrix + i*column*2 + j*2);
                if(temp < 0){
                    Size++;
                    temp = -temp;
                }

                if(temp < 10) Size += 1;
                else if(temp < 100) Size += 2;
                else if(temp < 1000) Size += 3;
                else if(temp < 10000) Size += 4;
                else if(temp < 100000) Size += 5;
                else if(temp < 1000000) Size += 6;
                else if(temp < 10000000) Size += 7;
                else if(temp < 100000000) Size += 8;
                else if(temp < 1000000000) Size += 9;
                else if(temp < 10000000000) Size += 10;

                if(Max < Size) Max = Size;

                // for Divisor
                temp = *(matrix + i*column*2 + j*2 + 1);
                if(temp < 10) Size = 1;
                else if(temp < 100) Size = 2;
                else if(temp < 1000) Size = 3;
                else if(temp < 10000) Size = 4;
                else if(temp < 100000) Size = 5;
                else if(temp < 1000000) Size = 6;
                else if(temp < 10000000) Size = 7;
                else if(temp < 100000000) Size = 8;
                else if(temp < 1000000000) Size = 9;
                else if(temp < 10000000000) Size = 10;

                if(Max < Size) Max = Size;
            }
        }
    }

    else {
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<column ; j++) {
                Size = 0;
                temp = *(matrix + i*column + j);
                if(temp < 0){
                    Size++;
                    temp = -temp;
                }

                if(temp < 10) Size += 1;
                else if(temp < 100) Size += 2;
                else if(temp < 1000) Size += 3;
                else if(temp < 10000) Size += 4;
                else if(temp < 100000) Size += 5;
                else if(temp < 1000000) Size += 6;
                else if(temp < 10000000) Size += 7;
                else if(temp < 100000000) Size += 8;
                else if(temp < 1000000000) Size += 9;
                else if(temp < 10000000000) Size += 10;

                if(Max < Size) Max = Size;
            }
        }
    }


    return Max;
}

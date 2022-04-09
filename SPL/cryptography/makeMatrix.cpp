#include "cryptography.h"

char * stringToMatrix(int *matrix, int row, int column, char *str) {
    int i, j;
    for(i=0 ; i<row ; i++) {
        for(j=0 ; j<column ; j++) {
            if(*str == '\0'){
                *matrix++ = 0;
            }
            else
                *matrix++ = (int) *str++;
        }
    }
    return str;
}

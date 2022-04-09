#include<bits/stdc++.h>
#include "matrix.h"

char * getNumber(char *p, char sign, int *matrix) {
    int i, j, k;
    char temp1[10], temp2[10];

    k = 0;
    while(*p >= '0' && *p <= '9') {
        temp1[k++] = *p;
        p++;
    }

    for(j = 0 ; k>=0 ; )
        temp2[j++] = temp1[--k];

    temp2[j] = '\0';

    for(j=0 , k=0 ; temp2[j] ; j++) {
        k = k + (temp2[j] - '0')*pow(10,j);
    }

    if(sign == '+')
        *matrix = k;
    else
        *matrix = -k;

    return --p;

}

#include<bits/stdc++.h>
#include "matrix.h"
using namespace std;

int gcd(int x, int y) {
    if(x*y == 0){
        cout << "Greatest Common Divisor cant't posible...." << endl;
        return 0 ;
    }

    if(x<0) x = -x;
    if(y<0) y = -y;

    int s, l, r;

    if(x > y) {
        l = x;
        s = y;
    }
    else {
        l = y;
        s = x;
    }

    r = l%s ;
    while(r != 0) {
        l = s;
        s = r;
        r = l%s;
    }
    //cout << "GCD   " << s << endl;
    return s;
}

long long gcd(long long x, long long y) {
    if(x*y == 0){
        cout << "Greatest Common Divisor cant't posible...." << endl;
        return 0 ;
    }

    if(x<0) x = -x;
    if(y<0) y = -y;

    long long s, l, r;

    if(x > y) {
        l = x;
        s = y;
    }
    else {
        l = y;
        s = x;
    }

    r = l%s ;
    while(r != 0) {
        l = s;
        s = r;
        r = l%s;
    }
    //cout << "GCD   " << s << endl;
    return s;
}

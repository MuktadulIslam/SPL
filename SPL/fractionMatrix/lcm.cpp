#include<bits/stdc++.h>
using namespace std;

// least common multiple
int lcm(int x, int y) {
    if(x<0) x = -x;
    if(y<0) y = -y;

    int s, l, r, m = x*y;

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
    return m/s;
}

#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int i, x[] = {45,3,6,94,56,8};
    sort(x,x+6);
    for(i=0 ; i<sizeof(x)/4 ; i++) cout << x[i] << "  ";
}

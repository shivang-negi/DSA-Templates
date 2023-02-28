#include<bits/stdc++.h>
using namespace std;

//Others miscellaneous

pair<long long,long long> reduceFraction(long long x, long long y) {
    long long d;
    d = __gcd(x, y);
 
    x = x / d;
    y = y / d;
 
    return {x,y};
}

int main() {

    return 0;
}
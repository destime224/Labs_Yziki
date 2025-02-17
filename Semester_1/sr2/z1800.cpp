// https://codeforces.com/problemset/problem/478/C
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long r, g, b;
    cin >> r >> g >> b;
    unsigned long long t = min((r+g+b)/3, r+g+b-max(r,max(g,b)));
    cout << t;
}
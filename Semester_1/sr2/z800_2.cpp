// https://codeforces.com/problemset/problem/231/A
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned n;
    cin >> n;

    unsigned allSolutions = 0;
    for (unsigned i = 0; i < n; i++) {
        unsigned short f, s, t, solutions;
        cin >> f >> s >> t;
        solutions = f+s+t;
        if (solutions > 1)
            allSolutions++; 
    }

    cout << allSolutions;
}
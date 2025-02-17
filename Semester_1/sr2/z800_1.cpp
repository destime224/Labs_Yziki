// https://codeforces.com/problemset/problem/4/A
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned w;
    cin >> w;

    if (w != 2 && w % 2 == 0)
        cout << "YES";
    else cout << "NO";
}
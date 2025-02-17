// https://codeforces.com/problemset/problem/69/A
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned n;
    cin >> n;

    int **forces = new int*[n];
    for (unsigned i = 0; i < n; i++) {
        forces[i] = new int[3];        
        cin >> forces[i][0] >> forces[i][1] >> forces[i][2];
    }

    int force_x = 0;
    int force_y = 0;
    int force_z = 0;

    for (unsigned i = 0; i < n; i++) {
        force_x += forces[i][0];
        force_y += forces[i][1];
        force_z += forces[i][2];
    }

    if (force_x == 0 && force_y == 0 && force_z == 0)
        cout << "YES";
    else cout << "NO";
}
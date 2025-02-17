// https://codeforces.com/problemset/problem/1/A
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long m, n, a;
    cin >> n >> m >> a;

    unsigned long long na = ceil(n/(double)a);
    unsigned long long ma = ceil(m/(double)a);

    unsigned long long result = na * ma;
    cout << result;
}
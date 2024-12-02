#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

float P(int n);
int irand(int a, int b);
void f3(int min, int max);
float f2(float a, float b);
int euclid(int a, int b);
float recurenct(float x, float eps);
float f6(float a, float b, float c, float x);
double f7(float x, float eps, int& n);
unsigned fibonachi(unsigned x);
void hfib(unsigned x, unsigned& first, unsigned& last);
bool isNumberHappyLoop(unsigned x, unsigned n);
bool isNumberHappyRecursive(unsigned x, unsigned n);
void hNumberHappyRecursive(unsigned x, unsigned n2, unsigned& x1, unsigned& x2);

using namespace std;
int main() {
    // Упражнение 1
    //int n;
    //cin >> n;
    //cout << P(n);

    // упражнение 2
    float a, b;
    cin >> a >> b;
    f2(a, b);

    // Упражнение 3
    // srand((unsigned)time(0));
    // int min, max;
    // cout << "Введите диапазон (min max): ";
    // cin >> min >> max;
    // f3(min, max);

    // Упражнение 4
    // int a, b;
    // cin >> a >> b;
    // cout << euclid(a, b);

    // Упражнение 5
    // float x, eps;
    // cin >> x >> eps;
    // cout << recurenct(x, eps);

    // Упражнение 6
    // float a, b, c, xs, xe, xd;
    // cin >> a >> b >> c >> xs >> xe >> xd;
    // int ai = a;
    // int bi = b;
    // int ci = c;
    
    // while (xs <= xe) {
        // float x;
        // if ((ai ^ bi) | (ai ^ ci) != 0)
            // x = xs;
        // else
            // x = floor(xs);
        // cout << x << " - " << f6(a, b, c, x) << endl;
        // xs += xd;
    // }

    // Упражнение 7
    // int n;
    // float eps, xs, xe, xd;
    // cin >> eps >> xs >> xe >> xd;
    // cout << "x " << "f " << "n " << endl;
    // while (xs <= xe) {
        // cout << xs << ' ' << f7(xs, eps, n) << ' ' << n << endl;
        // xs += xd;
    // }

    // Упражнение 8
    unsigned x;
    cin >> x;
    cout << fibonachi(x);

    // Упражнение 9
    // unsigned x, n;
    // cin >> x;
    // n = int(log10(x)+1);
    // if (isNumberHappyLoop(x, n))
        // cout << "Число счастливое (цикл)" << endl;
    // else
        // cout << "Число несчастливое (цикл)" << endl;

    // if (isNumberHappyRecursive(x, n))
        // cout << "Число счастливое (рекурсив)" << endl;
    // else
        // cout << "Число несчастливое (рекурсив)" << endl;
}

float P(int n) {
    float r = 0;
    for (int i = 1; i <= n; i++)
        r += 1/(float)(i * (i+1));
    return r;
}

int irand(int a, int b) {
    return rand()%(b - a + 1)+a;
}

float f2(float a, float b) {
    float x;
    do {
        cin >> x;
    } while (x < a || x > b);
}

void f3(int min, int max) {
    int m, r;
    m = irand(min, max);

    while (true) {
        cout << "Введите ваше число: ";
        cin >> r;
        if (r < m)
            cout << "Недолёт" << endl;
        else if (r > m)
            cout << "Перелёт" << endl;
        else
            break;
    };
}

int euclid(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

float recurenct(float x, float eps) {
    float y = 1;
    float last;
    do {
        last = y;
        y = 0.5f*(y + x/y);
    } while (abs(y-last)>eps);
    return y;
}

float f6(float a, float b, float c, float x) {
    if (x + c < 0 && a != 0)
        return -a * pow(x, 3) - b;
    if (x + c > 0 && a == 0)
        return (x-a)/(x-c);
    return (x/c)+(c/x);
}

double f7(float x, float eps, int& n) {
    double y = 1;
    double ch = 1;
    for (n = 0; abs(ch)>eps; n++) {
        ch *= -(x*x)/((2*n+2)*(2*n+1));
        y += ch;
    }
    return y;
}

unsigned fibonachi(unsigned x) {
    if (x == 0) return 0;
    unsigned last, first = {1};
    //cout << last << ' ' << first;
    hfib(x, first, last);
    return first;
}

void hfib(unsigned x, unsigned& first, unsigned& last) {
    x--;
    if (x > 0) {
        unsigned c = first;
        first += last;
        last = c;
        hfib(x, first, last); 
    }
}

bool isNumberHappyLoop(unsigned x, unsigned n) {
    unsigned x1, x2 = {0};
    for (unsigned i = 0; i < n; i++) {
        short number = x % int(pow(10, i+1)) / int(pow(10, i));
        if (i < n/2)
            x1 += number;
        else
            x2 += number;
    }
    if (x1 == x2) return true;
    return false;
}

bool isNumberHappyRecursive(unsigned x, unsigned n) {
    unsigned x1, x2 = {0};
    hNumberHappyRecursive(x, n/2, x1, x2);
    if (x1 == x2) return true;
    return false;
}

void hNumberHappyRecursive(unsigned x, unsigned n2, unsigned& x1, unsigned& x2) {
    unsigned n = log10(x)+1;
    unsigned number = x % 10;
    if (n <= n2) x1 += number;
    else x2 += number;
    if (n != 1) hNumberHappyRecursive(x / 10, n2, x1, x2);
}
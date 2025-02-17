#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // 1 упражнение
    // int a, b, h;
    // std::cin >> a >> b >> h;
    // float abh = a*b*h;
    // float S = abh/6;
    // std::cout << S;

    // 2 упражнение
    // float f;
    // std::cin >> f;
    // float c = ((f - 32) * 5) / 9;
    // std::cout << c;

    // 3 упражнение
    // float a, b, c;
    // std::cin >> a >> b >> c;
    // float p = (a + b + c) / 2;
    // float S = sqrt(p * (p - a) * (p - b) * (p - c));
    // std::cout << S;

    // 4 упражнение
    // unsigned short hours1, minutes1, seconds1;
    // std::cin >> hours1 >> minutes1 >> seconds1;
    // unsigned short hours2, minutes2, seconds2;
    // std::cin >> hours2 >> minutes2 >> seconds2;
    
    // unsigned int onlySeconds1 = hours1 * 3600 + minutes1 * 60 + seconds1;
    // unsigned int onlySeconds2 = hours2 * 3600 + minutes2 * 60 + seconds2;

    // unsigned int onlySeconds3 = onlySeconds2 - onlySeconds1;
    // unsigned short hours3, minutes3, seconds3;
    // hours3 = onlySeconds3 / 3600;
    // minutes3 = (onlySeconds3 % 3600) / 60;
    // seconds3 = onlySeconds3 % 60;

    // std::cout << hours3 << ' ' << minutes3 << ' ' << seconds3;
    
    // Индивидуальные задания
    // 1 упражнение
    float x;
    std::cin >> x;
    float Z1f = (cos(x) + sin(x))/(cos(x) - sin(x));
    float Z2f = tan(2 * x) + 1.f/cos(2 * x);

    double y;
    std::cin >> y;
    double Z1d = (cos(y) + sin(y))/(cos(y) - sin(y));
    double Z2d = tan(2 * y) + 1./cos(2 * y);

    // 2 упражнение
    std::cout << std::setprecision(20) << std::fixed;
    std::cout << "Z1f - Z2f: " << std::abs(Z1f - Z2f) << std::endl;
    std::cout << "Z1d - Z2d: " << std::abs(Z1d - Z2d) << std::endl;
    std::cout << "Z1f - Z1d: " << std::abs(Z1f - Z1d) << std::endl;

    // 3 упражнение
    // ...
}
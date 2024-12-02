#include <iostream>
#include <string>
#include <cmath>

float exercise1(int x);
bool fun(float x, float y, float a, float b, float R = 1);

int main() {
    // Упражнение 1
    // float x;
    // std::cin >> x;
    // std::cout << exercise1(x);

    // Упражнение 2
    float a, b, c;
    std::cin >> a >> b >> c;
    if (a >= b && a >= c)
        std::cout << a << std::endl;
    else if (b >= a && b >= c)
        std::cout << b << std::endl;
    else
        std::cout << c << std::endl;

    // Упражнение 3
    unsigned short age;
    std::cin >> age;

    std::string text;
    if (age >= 10 && age <= 20)
        text = "лет";
    else { 
        switch (age % 10)
        {
        case 1:
            text = "год";
        case 2:
        case 3:
        case 4:
            text = "года";
        default:
            text = "лет";
        }
    }
    std::cout << "Мне " << age << " " << text << std::endl;

    // Упражнение 4
    float x, y, a, b, R;
    std::cin >> R >> a >> b >> x >> y;
    if (fun(x, y, a, b, R))
        std::cout << "Точка попадает в область" << std::endl;
    else
        std::cout << "Точка не попадает в область" << std::endl;
}

float exercise1(int x) {
    if (x <= -2)
        return 0;
    else if (x <= 0)
        return 2 + x;
    else if (x <= 2)
        return 2 - 2 * x;
    else
        return -2; 
}

bool fun(float x, float y, float a, float b, float R) {
    if (x >= 0 && x <= a && y >= 0 && y <= b && x*x + y*y >= R*R) return true;
    if (x <= 0 && x >= -a && y <= 0 && y >= -b && x*x + y*y <= R*R) return true;
    return false;
}
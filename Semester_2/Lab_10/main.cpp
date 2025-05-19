#include <cstdlib>
#include <iostream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <algorithm>

#define EPS 0.000000001

using namespace std;

/* Задание 1 */
class Complex {
    double Re, Im;

public:
    Complex() {
        Re = 0;
        Im = 0;
    }

    Complex(double a, double b = 0) {
        Re = a;
        Im = b;
    }

    Complex(Complex &X) {
        Re = X.Re;
        Im = X.Im;
    }

    ~Complex() {}

    void setRe(double x) { Re = x; }
    void setIm(double x) { Im = x; }
    double getRe() { return Re; }
    double getIm() { return Im; }

    friend void printComplex(Complex A);
    friend void printTrigonometricForm(Complex A);
    friend Complex operator+(Complex A, Complex B);
    friend Complex operator-(Complex A, Complex B);
    friend Complex operator*(Complex A, Complex B);
    friend Complex operator/(Complex A, Complex B);
    friend bool operator==(Complex A, Complex B);
    friend bool operator!=(Complex A, Complex B);
    friend bool operator>(Complex A, Complex B);
    friend bool operator<(Complex A, Complex B);
    friend bool operator>=(Complex A, Complex B);
    friend bool operator<=(Complex A, Complex B);
    friend ostream &operator<<(std::ostream &out, Complex &X);

    Complex &operator=(const Complex &A) {
        if (&A == this)
            return *this;
        this->Re = A.Re;
        this->Im = A.Im;
        return *this;
    }

    string toString() {
        ostringstream ss;
        if (abs(Im) < 0.0000001) {
            ss << Re;
            return ss.str();
        }
        if (Im > 0)
            ss << Re << "+" << Im << "i";
        else
            ss << Re << Im << "i";
        return ss.str();
    }

    double getModule() {
        return sqrt(Re*Re + Im*Im);
    }
};

ostream &operator<<(std::ostream &out, Complex &X) {
    out << X.toString();
    return out;
}

bool operator==(Complex A, Complex B) {
    if (abs(A.Re - B.Re) < EPS && abs(A.Im - B.Im) < EPS)
        return true;
    return false;
}

bool operator!=(Complex A, Complex B) {
    return !(A == B);
}

bool operator>(Complex A, Complex B) {
    if (A.getModule() > B.getModule())
        return true;
    return false;
}

bool operator<(Complex A, Complex B) {
    if (A.getModule() < B.getModule())
        return true;
    return false;
}

bool operator>=(Complex A, Complex B) {
    return (A == B || A > B);
}

bool operator<=(Complex A, Complex B) {
    return (A == B || A < B);
}

Complex operator+(Complex A, Complex B) {
    Complex C;
    C.Re = A.Re + B.Re;
    C.Im = A.Im + B.Im;
    return C;
}

Complex operator-(Complex A, Complex B) {
    Complex C;
    C.Re = A.Re - B.Re;
    C.Im = A.Im - B.Im;
    return C;
}

Complex operator*(Complex A, Complex B) {
    Complex C;
    C.Re = A.Re*B.Re - A.Im*B.Im;
    C.Im = A.Re*B.Im + A.Im*B.Re;
    return C;
}

Complex operator/(Complex A, Complex B) {
    Complex C;
    C.Re = (A.Re*B.Re + A.Im*B.Im) / (B.Re*B.Re + B.Im*B.Im);
    C.Im = (A.Im*B.Re - A.Re*B.Im) / (B.Re*B.Re + B.Im*B.Im);
    return C;
}

void printComplex(Complex A) {
    cout << A.Re;
    if (A.Im < 0)
        cout << A.Im << "i" << endl;
    else
        cout << "+" << A.Im << "i" << endl;
}

void printTrigonometricForm(Complex A) {
    double ang = 180 * atan2(A.Im, A.Re) / M_PI;
    cout << A.getModule() << "(sin" << ang << "°+cos" << ang << "°)";
}

/* Задание 2 */
class BaggageLocker {
    unsigned number;
    double length, width, height; 
    bool busy;
    string accessCode;
public:
    BaggageLocker() {
        number = 0;
        length = 1; width = 1; height = 1;
        busy = false;
        accessCode = "0000";
    }

    BaggageLocker(unsigned number, double length, double width, double height, string code) {
        this->number = number;
        if (length <= 0 || width <= 0 || height <= 0) throw invalid_argument("Any side cannot be negative");
        this->length = length; this->width = width; this->height = height;
        this->busy = false;
        if (!isAccessCodeValid(code)) throw invalid_argument("Access Code is not valid");
        accessCode = code;
    }

    BaggageLocker(BaggageLocker &locker) {
        BaggageLocker(locker.number, locker.length, locker.width, locker.height, locker.accessCode);
    }

    bool isAccessCodeValid(string code) {
        if (code.length() != 4) return false;
        bool r = true;
        for (auto s: code) {
            if (!isdigit(s)) r = false;
        }
        return r;
    }

    double getStorageSize() {
        return length * width * height;
    }

    bool getLockerBusy() {
        return busy;
    }

    void setLockerBusy() {
        busy = !busy;
    }

    void setLockerBusy(bool b) {
        busy = b;
    }

    bool canBaggageGetIntoLocker(double baggageLength, double baggageWidth, double baggageHeight) {
        double baggageSize[3] = {length, width, height};
        sort(baggageSize, baggageSize+3);
        double lockerSize[3] = {baggageLength, baggageWidth, baggageHeight};
        sort(lockerSize, lockerSize+3);

        if (
            // (baggageLength <= length && baggageWidth <= width && baggageHeight <= height) ||
            // (baggageLength <= width && baggageWidth <= length && baggageHeight <= height) ||
            // (baggageLength <= length && baggageWidth <= height && baggageHeight <= width) ||
            // (baggageLength <= height && baggageWidth <= width && baggageHeight <= length) ||
            // (baggageLength <= width && baggageWidth <= height && baggageHeight <= length) ||
            // (baggageLength <= height && baggageWidth <= length && baggageHeight <= width)
            baggageSize[0] <= lockerSize[0] && baggageSize[1] <= lockerSize[1] && baggageSize[2] <= lockerSize[2]
        ) return true;
        return false;
    }
};

/* Задание 3 */
class figure{
protected: 
	double x, y;
public:
	figure(double a=0, double b=0){x=a; y=b;}
	virtual double area() {return 0;}
};

class triangle: public figure {
    double z;
public:
    triangle(double a, double b, double c) {
        if (!canTriangleExist(a, b, c)) throw invalid_argument("Triangle with given sides doesn't exist");
        x=a; y=b; z=c; 
    }

    bool canTriangleExist(double a, double b, double c) {
        auto maxValue = max(a, max(b, c));
        if (((a+b+c)-maxValue > maxValue) && a > 0 && b > 0 && c > 0) return true;
        return false;
    }

    virtual double area() override {
        auto poluperimetr = (x+y+z)/2.0;
        return sqrt(poluperimetr * (poluperimetr-x) * (poluperimetr - y) * (poluperimetr - z));
    }
};

/* Задание 4 */
class Pair {
protected:
    double a, b;

public:
    Pair(double a = 0, double b = 0) {
        this->a = a;
        this->b = b;
    }

    double getA() {return a;}
    void setA(double a) {this->a = a;}

    double getB() {return b;}
    void setB(double b) {this->b = b;}

    Pair operator+(Pair other) {
        return Pair(a + other.a, b + other.b);
    }

    Pair operator*(Pair other) {
        return Pair(a * other.a, b * other.b);
    }
};

class Complex2: public Pair {
    Complex2(double a = 0, double b = 0): Pair(a, b){}

    Complex2 operator+(Complex2 other) {
        auto result = Pair::operator+(other);
        return Complex2(result.getA(), result.getB());
    }

    Complex2 operator*(Complex2 other) {
        return Complex2(a * other.a - b * other.b, a * other.b + b * other.a);
    }

    Complex2 operator-(Complex2 other) {
        return Complex2(a - other.a, b - other.b);
    }
};

/* Задание 5 */
class InvalidRadius: public exception {
    string message;
public:
    InvalidRadius(const string &message): message(message){}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

double ringArea(double innerRadius, double externalRadius) {
    if (innerRadius <= 0) throw InvalidRadius("Inner radius must be greater than 0");
    if (externalRadius <= 0) throw InvalidRadius("External radius must be greater than 0");
    if (innerRadius >= externalRadius) throw InvalidRadius("Inner radius must be smaller than external one");

    double innerCircle = (double)M_PI * innerRadius * innerRadius;
    double externalCircle = (double)M_PI * externalRadius * externalRadius;
    return externalRadius - innerRadius;
}

int main() {
    try {
        cout << ringArea(1, 2) << endl;
    } catch(InvalidRadius &e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}
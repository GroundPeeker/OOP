#include <iostream>
#include <exception>

class Rational {
public:
    Rational(int a, int b): a(a), b(b) {
        if (b == 0) {
            b = 1;
        }
        reduce();}
    Rational(Rational& other): a(other.a), b(other.b) {reduce();}
    void reduce() {
        int c = a;
        int d = b;
        while (c != d) {
            if (c > d) {
                c -= d;
            } else {
                d -= c;
            }
        }
        a /= d;
        b /= d;
    }
    void add(Rational& r) {
        a = a * r.b + b * r.a;
        b *= r.b;
        reduce();
    }
    void sub(Rational& r) {
        a = a * r.b - b * r.a;
        b *= r.b;
        reduce();
    }
    void mul(Rational& r) {
        a *= r.a;
        b *= r.b;
        reduce();
    }
    void div(Rational& r) {
        a *= r.b;
        b *= r.a;
        reduce();
    }
    int a, b;
};

std::ostream& operator<<(std::ostream& os, const Rational& rat) {
    std::cout << rat.a << "/" << rat.b << std::endl;
    return os;
}


int main() {
    Rational a(1, 2);
    Rational b(1, 3);
    a.add(b);
    std::cout << a << std::endl;
    return 0;
}

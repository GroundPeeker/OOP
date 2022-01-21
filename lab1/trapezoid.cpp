//
// Created by queens_gambit on 16.01.2022.
//

#include "trapezoid.h"

size_t Trapezoid::VertexesNumber() {
    return 4;
}

double Trapezoid::Area() {
    double A = a.dist(b);
    double B = c.dist(d);
    double C = a.dist(d);
    double D = b.dist(c);
    double S = (A + B) / 2 * sqrt(C*C - ((B-A)*(B-A) + C*C - D*D)/(2*(B-A))*((B-A)*(B-A) + C*C - D*D)/(2*(B-A)));
    return S;
}

void Trapezoid::Print(std::ostream &os) {
    os << "Trapezoid: " << a << b << c << d << std::endl;
}

Trapezoid::Trapezoid() {}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

Trapezoid::Trapezoid(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d;
    std::cout << "Trapezoid created via istream" << std::endl;
}

Trapezoid::Trapezoid(const Trapezoid &other) : Trapezoid(other.a, other.b, other.c, other.d) {
    std::cout << "Made copy of Trapezoid" << std::endl;
}

Trapezoid::~Trapezoid() {
    std::cout << "Trapezoid deleted" << std::endl;
}
//
// Created by queens_gambit on 16.01.2022.
//

#include "rhombus.h"

size_t Rhombus::VertexesNumber() {
    return 4;
}

double Rhombus::Area() {
    return a.dist(c) * b.dist(d) / 2;
}

void Rhombus::Print(std::ostream &os) {
    os << "Rhombus: " << a << b << c << d << std::endl;
}

Rhombus::Rhombus() {}

Rhombus::Rhombus(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

Rhombus::Rhombus(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d;
    std::cout << "Rhombus created via istream" << std::endl;
}

Rhombus::Rhombus(const Rhombus &other) : Rhombus(other.a, other.b, other.c, other.d) {
    std::cout << "Made copy of Rhombus" << std::endl;
}

Rhombus::~Rhombus() {
    std::cout << "Rhombus deleted" << std::endl;
}
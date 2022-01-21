#include "rectangle.h"

size_t Rectangle::VertexesNumber() {
    return 4;
}

double Rectangle::Area() {
    return a.dist(b) * a.dist(d);
}

void Rectangle::Print(std::ostream &os) {
    os << "Rectangle: " << a << b << c << d << std::endl;
}

Rectangle::Rectangle() {}

Rectangle::Rectangle(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

Rectangle::Rectangle(std::istream &is) {
    std::cout << "Enter data:" << std::endl;
    is >> a >> b >> c >> d;
    std::cout << "Rectangle created via istream" << std::endl;
}

Rectangle::Rectangle(const Rectangle &other) : Rectangle(other.a, other.b, other.c, other.d) {
    std::cout << "Made copy of rectangle" << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}
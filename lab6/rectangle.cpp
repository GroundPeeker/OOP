#include "rectangle.h"

std::istream& operator>>(std::istream& is, Rectangle& r) {
    std::cout << "Enter data: " << std::endl;
    is >> r.a >> r.b >> r.c >> r.d;
    return is;
}

std::ostream& operator<<(std::ostream& os, Rectangle& r) {
    os << "Pentagon: " << r.a << r.b << r.c << r.d;
    return os;
}

Rectangle& Rectangle::operator=(const Rectangle &other) {
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    this->d = other.d;
    return *this;
}

bool Rectangle::operator==(const Rectangle &other) {
    return a == other.a && b == other.b && c == other.c;
}

void Rectangle::Print(std::ostream &os) {
    os << "Rectangle: " << a << b << c << d << std::endl;
}

size_t Rectangle::VertexesNumber() {
    return 4;
}

double Rectangle::Area() {
    return a.dist(b) * a.dist(d);
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
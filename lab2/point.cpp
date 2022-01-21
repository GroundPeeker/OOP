#include "point.h"

#include <cmath>

bool Point::operator==(const Point &other) {
    return this->x == other.x && this->y == other.y;
}

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(std::istream &is) {
    is >> x >> y;
}

double Point::dist(Point &other) {
    double dx = (other.x - x);
    double dy = (other.y - y);
    return std::sqrt((dx * dx) + (dy * dy));
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
#ifndef OOP1_TRAPEZOID_H
#define OOP1_TRAPEZOID_H

#include "figure.h"

class Trapezoid : Figure {
public:
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;

    Trapezoid();
    Trapezoid(Point a, Point b, Point c, Point d);
    Trapezoid(std::istream &is);
    Trapezoid(const Trapezoid &other);
    virtual ~Trapezoid();
private:
    Point a, b, c, d;
};


#endif //OOP1_TRAPEZOID_H

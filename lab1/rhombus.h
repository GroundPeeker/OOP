
#ifndef OOP1_RHOMBUS_H
#define OOP1_RHOMBUS_H

#include "figure.h"
class Rhombus : Figure {
public:
    size_t VertexesNumber() override;
    double Area() override;
    void Print(std::ostream &os) override;

    Rhombus();
    Rhombus(Point a, Point b, Point c, Point d);
    Rhombus(std::istream &is);
    Rhombus(const Rhombus &other);
    virtual ~Rhombus();
private:
    Point a, b, c, d;
};

#endif //OOP1_RHOMBUS_H

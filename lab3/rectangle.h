#ifndef OOP1_RECTANGLE_H
#define OOP1_RECTANGLE_H

#include "figure.h"
class Rectangle : Figure {
public:
    friend std::istream& operator>>(std::istream& is, Rectangle& p);
    friend std::ostream& operator<<(std::ostream& os, Rectangle& p);
    bool operator==(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    void Print(std::ostream &os) override;
    size_t VertexesNumber() override;
    double Area() override;
    Rectangle();
    Rectangle(Point a, Point b, Point c, Point d);
    Rectangle(std::istream &is);
    Rectangle(const Rectangle &other);
    virtual ~Rectangle();
private:
    Point a, b, c, d;
};
#endif //OOP1_RECTANGLE_H

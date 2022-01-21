#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"

int main() {
    Rectangle re(std::cin);
    re.Print(std::cout);
    std::cout << "Number of vertex is " << re.VertexesNumber() << std::endl;
    std::cout << "Area is " << re.Area() << std::endl;
    std::cout << "---------------------------" << std::endl;
    Trapezoid t(std::cin);
    t.Print(std::cout);
    std::cout << "Number of vertex is " << t.VertexesNumber() << std::endl;
    std::cout << "Area is " << t.Area() << std::endl;
    std::cout << "---------------------------" << std::endl;
    Rhombus rh(std::cin);
    re.Print(std::cout);
    std::cout << "Number of vertex is " << rh.VertexesNumber() << std::endl;
    std::cout << "Area is " << rh.Area() << std::endl;
}
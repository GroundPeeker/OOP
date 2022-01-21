#include "rectangle.h"
#include "TVector.h"
#include <memory>
#include <string>

int main() {
    std::string command;
    TVector<Rectangle> v;

    while (std::cin >> command) {
        if (command == "print")
            std::cout << v;
        else if (command == "insertlast") {
            Rectangle r;
            std::cin >> r;
            std::shared_ptr<Rectangle> d(new Rectangle(r));
            v.InsertLast(d);
        }
        else if (command == "removelast") {
            v.RemoveLast();
        }
        else if (command == "last") {
            std::cout << v.Last();
        }
        else if (command == "idx") {
            int idx;
            std::cin >> idx;
            std::cout << v[idx];
        }
        else if (command == "clear") {
            v.Clear();
        }
        else if (command == "empty") {
            if (v.Empty()) std::cout << "Yes" << std::endl;
            else std::cout << "No" << std::endl;
        }
    }
    return 0;
}
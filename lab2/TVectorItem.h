#ifndef LAB1_TVECTORITEM_H
#define LAB1_TVECTORITEM_H

#include <iostream>
#include "rectangle.h"

class TVectorItem {
public:
    TVectorItem(const Rectangle& rectangle);

    TVectorItem(const TVectorItem& other);

    Rectangle& GetRectangle();

    TVectorItem(){}

    friend std::ostream &operator<<(std::ostream &os, TVectorItem &p);


private:
    Rectangle p;
};

#endif //LAB1_TVECTORITEM_H

#include <iostream>
#include "TVectorItem.h"

TVectorItem::TVectorItem(const Rectangle& pentagon){
    p = pentagon;
}

TVectorItem::TVectorItem(const TVectorItem& other){
    p = other.p;
}

Rectangle& TVectorItem::GetRectangle() {
    return p;
}

std::ostream &operator<<(std::ostream &os, TVectorItem &p){
    os << p;
    return os;
}

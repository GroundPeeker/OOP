#include "TVectorItem.h"

template<class T>
TVectorItem<T>::TVectorItem(const std::shared_ptr<T>& other) {
    r = other;
}

template<class T>
TVectorItem<T>::TVectorItem(const std::shared_ptr<TVectorItem<T>>& other) {
    r = other->r;
}

template<class T>
std::shared_ptr<T>& TVectorItem<T>::getItem() {
    return r;
}

template<class A>
std::ostream& operator<<(std::ostream& os, TVectorItem<A>& r) {
    os << *r.getItem();
    return os;
}

template class TVectorItem<Rectangle>;
template std::ostream& operator<<(std::ostream& os, TVectorItem<Rectangle>& r);
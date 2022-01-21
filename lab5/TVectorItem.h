#ifndef OOP2_TVECTORITEM_H
#define OOP2_TVECTORITEM_H
#include "rectangle.h"
#include <memory>

template<class T>
class TVectorItem {
public:
    TVectorItem(const std::shared_ptr<T>& other);

    TVectorItem(const std::shared_ptr<TVectorItem<T>>& other);

    std::shared_ptr<T>& getItem();

    TVectorItem() {}

    template<class A>friend std::ostream& operator<<(std::ostream &os, TVectorItem<A> &p);

private:
    std::shared_ptr<T> r;
};
#endif //OOP2_TVECTORITEM_H

#ifndef OOP2_TVECTOR_H
#define OOP2_TVECTOR_H

#include <iostream>
#include <memory>
#include <cstdlib>

#include "rectangle.h"

class TVector {
public:
    TVector();

    TVector(const TVector &);

    virtual ~TVector();

    size_t Length() const {
        return length_;
    }

    bool Empty() const {
        return !length_;
    }

    const std::shared_ptr<Rectangle> &operator[](const size_t index) const {
        return data_[index];
    }

    std::shared_ptr<Rectangle> &Last() const {
        return data_[length_ - 1];
    }

    void InsertLast(const std::shared_ptr<Rectangle> &);

    void EmplaceLast(const Rectangle &&);

    void Remove(const size_t index);

    Rectangle RemoveLast() {
        return *data_[--length_];
    }

    void Clear();

    friend std::ostream &operator<<(
            std::ostream &, const TVector &);

private:
    void _Resize(const size_t new_capacity);

    std::shared_ptr<Rectangle> *data_;
    size_t length_, capacity_;
};
#endif //OOP2_TVECTOR_H

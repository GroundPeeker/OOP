#ifndef OOP2_TVECTOR_H
#define OOP2_TVECTOR_H

#include <iostream>
#include <memory>
#include <cstdlib>

#include "TIterator.h"

template <typename T>
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

    const std::shared_ptr<T> &operator[](const size_t index) const {
        return data_[index];
    }

    std::shared_ptr<T> &Last() const {
        return data_[length_ - 1];
    }

    void InsertLast(const std::shared_ptr<T> &);

    void EmplaceLast(const T &&);

    void Remove(const size_t index);

    T RemoveLast() {
        return *data_[--length_];
    }

    void Clear();

    TIterator<T> begin() {
        return TIterator<T>(data_);
    }

    TIterator<T> end() {
        return TIterator<T>(data_ + length_);
    }

    template<typename TF>
    friend std::ostream &operator<<(
            std::ostream &, const TVector<TF> &);

private:
    void _Resize(const size_t new_capacity);

    std::shared_ptr<T> *data_;
    size_t length_, capacity_;
};
#endif //OOP2_TVECTOR_H

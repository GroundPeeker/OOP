//
// Created by queens_gambit on 16.01.2022.
//

#include "TVector.h"
#include "rectangle.h"
#include <cassert>

template <typename T>
TVector<T>::TVector()
        : data_(new std::shared_ptr<T>[32]),
          length_(0), capacity_(32) {}

template <typename T>
TVector<T>::TVector(const TVector &vector)
        : data_(new std::shared_ptr<T>[vector.capacity_]),
          length_(vector.length_), capacity_(vector.capacity_) {
    std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

template <typename T>
TVector<T>::~TVector() {
    delete[] data_;
}

template <typename T>
void TVector<T>::_Resize(const size_t new_capacity) {
    std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
    std::copy(data_, data_ + capacity_, newdata);
    delete[] data_;
    data_ = newdata;
    capacity_ = new_capacity;
}

template <typename T>
void TVector<T>::InsertLast(const std::shared_ptr<T> &item) {
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
    data_[length_++] = item;
}

template <typename T>
void TVector<T>::EmplaceLast(const T &&item) {
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
    data_[length_++] = std::make_shared<T>(item);
}

template <typename T>
void TVector<T>::Remove(const size_t index) {
    std::copy(data_ + index + 1, data_ + length_, data_ + index);
    --length_;
}

template <typename T>
void TVector<T>::Clear() {
    delete[] data_;
    data_ = new std::shared_ptr<T>[32];
    length_ = 0;
    capacity_ = 32;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TVector<T> &vector) {
    for (size_t i = 0; i < vector.length_; ++i)
        os << (*vector.data_[i]);
    os << std::endl;
    return os;
}

template class TVector<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const TVector<Rectangle >& arr);
//
// Created by queens_gambit on 16.01.2022.
//

#include "TVector.h"
#include "rectangle.h"
#include <cassert>

TVector::TVector()
        : data_(new std::shared_ptr<Rectangle>[32]),
          length_(0), capacity_(32) {}

TVector::TVector(const TVector &vector)
        : data_(new std::shared_ptr<Rectangle>[vector.capacity_]),
          length_(vector.length_), capacity_(vector.capacity_) {
    std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

TVector::~TVector() {
    delete[] data_;
}

void TVector::_Resize(const size_t new_capacity) {
    std::shared_ptr<Rectangle> *newdata = new std::shared_ptr<Rectangle>[new_capacity];
    std::copy(data_, data_ + capacity_, newdata);
    delete[] data_;
    data_ = newdata;
    capacity_ = new_capacity;
}

void TVector::InsertLast(const std::shared_ptr<Rectangle> &item) {
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
    data_[length_++] = item;
}

void TVector::EmplaceLast(const Rectangle &&item) {
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
    data_[length_++] = std::make_shared<Rectangle>(item);
}

void TVector::Remove(const size_t index) {
    std::copy(data_ + index + 1, data_ + length_, data_ + index);
    --length_;
}

void TVector::Clear() {
    delete[] data_;
    data_ = new std::shared_ptr<Rectangle>[32];
    length_ = 0;
    capacity_ = 32;
}

std::ostream &operator<<(std::ostream &os, const TVector &vector) {
    for (size_t i = 0; i < vector.length_; ++i)
        os << (*vector.data_[i]);
    os << std::endl;
    return os;
}

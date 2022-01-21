//
// Created by queens_gambit on 21.01.2022.
//

#include "TStack.h"

template <typename T>
TStack<T>::TStack(): data(new std::shared_ptr<T>[32]), length(0), capacity(32) {}

template <typename T>
TStack<T>::TStack(const TStack &tStack) : data(new std::shared_ptr<T>[tStack.capacity]), length(tStack.length), capacity(tStack.capacity) {
    std::copy(tStack.data, tStack.data + tStack.length, data);
}

template <typename T>
TStack<T>::~TStack() {
    delete[] data;
}

template <typename T>
void TStack<T>::Resize(const size_t new_capacity) {
    std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
    std::copy(data, data + capacity, newdata);
    delete[] data;
    data = newdata;
    capacity = new_capacity;
}

template <typename T>
void TStack<T>::Emplace(const T &&item) {
    if (length >= capacity)
        Resize(capacity << 1);
    data[length] = std::make_shared<T>(item);
}

template <typename T>
void TStack<T>::Push(const std::shared_ptr<T> &item) {
    if (length >= capacity)
        Resize(capacity << 1);
    data[length++] = item;
}

template <typename T>
void TStack<T>::Clear() {
    delete[] data;
    data = new std::shared_ptr<T>[32];
    length = 0;
    capacity = 32;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const  TStack<T> &stack) {
    for (size_t i = 0; i < stack.length; ++i)
        os << (*stack.data[stack.length - 1 - i]);
    return os;
}

template class TStack<void *>;
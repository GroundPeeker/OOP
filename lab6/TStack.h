//
// Created by queens_gambit on 21.01.2022.
//

#ifndef OOP6_TSTACK_H
#define OOP6_TSTACK_H

#include <ostream>
#include <memory>
#include <cstdlib>

template <typename T>
class TStack {
public:
    TStack(const TStack &);

    virtual ~TStack();

    size_t Length() const {
        return length;
    }

    bool Empty() const {
        return !length;
    }

    std::shared_ptr<T> &Top() const {
        return data[length];
    }

    void Emplace(const T &&);

    void Push(const std::shared_ptr<T> &);

    T Pop() {
        return *data[--length];
    }

    void Clear();

    template<typename TF>
    friend std::ostream &operator<<(std::ostream &, const TStack<TF> &);

    TStack();

private:
    void Resize(const size_t new_capacity);

    std::shared_ptr<T> *data;

    size_t length, capacity;
};


#endif //OOP6_TSTACK_H

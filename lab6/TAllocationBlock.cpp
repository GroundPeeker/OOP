//
// Created by queens_gambit on 21.01.2022.
//

#include "TAllocationBlock.h"

#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : size(size), count(count), budget(count), used_blocks(new char[size * count]) {
    for (size_t i = 0; i < count; ++i)
        free_blocks.Emplace((void *)(used_blocks + (i * size)));
}

TAllocationBlock::~TAllocationBlock() {
    delete[] used_blocks;
}

void TAllocationBlock::Resize(size_t new_count) {
    char *newdata = new char[size * new_count];
    std::copy(used_blocks, used_blocks + (size * count), newdata);
    delete[] used_blocks;
    used_blocks = newdata;
    count = new_count;
}

void *TAllocationBlock::Allocate(size_t size) {
    if (size != this->size) {
        std::cerr << "This block allocates " << this->size << "bytes only. "
            << "You tried to allocate " << size << std::endl;
        return 0;
    }

    if (!budget) {
        size_t old_count = count;
        Resize(count << 1);
        budget += (count - old_count);

        for (size_t i = old_count; i < count; ++i) {
            free_blocks.Emplace((void*)(used_blocks + (i * size)));
        }
    }
    --budget;

    return free_blocks.Pop();
}

void TAllocationBlock::Free(void *pointer) {
    free_blocks.Push(std::make_shared<void *>(pointer));
    ++budget;
}


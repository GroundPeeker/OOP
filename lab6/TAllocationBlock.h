//
// Created by queens_gambit on 21.01.2022.
//

#ifndef OOP6_TALLOCATIONBLOCK_H
#define OOP6_TALLOCATIONBLOCK_H

#include "TStack.h"
class TAllocationBlock {
public:
    TAllocationBlock(size_t size, size_t count);

    ~TAllocationBlock();

    void *Allocate(size_t size);

    void Free(void *pointer);

    bool FreeBlocksAvailable() const {
        return budget;
    }

private:
    void Resize(size_t new_count);

    size_t size;
    size_t count;
    size_t budget;

    char *used_blocks;
    TStack<void *> free_blocks;
};


#endif //OOP6_TALLOCATIONBLOCK_H

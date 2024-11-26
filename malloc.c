#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct block {
    size_t size;
    struct block* next;
    int free;
} block_t;
block_t* first_block = NULL;

void initialize_heap() {
    block_t* first_block = get_me_blocks(sizeof(block_t));
    first_block->size = sizeof(block_t);
    first_block->next = NULL;
    first_block->free = 1;
}



void* get_me_blocks(ssize_t how_much ) {
    void* ptr = sbrk(0);
    sbrk(how_much);
    return ptr;
}

void* malloc(size_t size) {
    void* ptr = get_me_blocks(size);
    if (ptr == (void*)-1) {
        return NULL;
    }
    block_t* prev_block = NULL;
    block_t* current_block = first_block;
    while (current_block != NULL) {
        if (current_block->free && current_block->size >= size) {
            current_block->free = 0;
            return (void*)(current_block + 1);
        }
        prev_block = current_block;
        current_block = current_block->next;
    }

}
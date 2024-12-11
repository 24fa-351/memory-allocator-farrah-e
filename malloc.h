#ifndef MALLOC_H
#define MALLOC_H

void initialize_heap();
void* malloc(int size);
void freeMemory(void* ptr);
void* get_me_blocks(int how_much);

#endif
#ifndef _INCLUDE_CONTIGUOUS_MEMORY_ALLOCATOR_H_
#define _INCLUDE_CONTIGUOUS_MEMORY_ALLOCATOR_H_

#include "include/types.h"

uint32 CmaAlloc(uint32 size);
void CmaFree(uint32 addr);

void CmaInit(uint32 heap_addr, uint32 heap_size);

#endif

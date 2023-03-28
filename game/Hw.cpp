#include "Hw.h"
#include "shared.h"

void *Hw::cHeapVariable::AllocateMemory(size_t size, Hw::cHeapVariable *heap)
{
    return ((void *(__cdecl*)(size_t, Hw::cHeapVariable*))(shared::base + 0x9D3500))(size, heap);
}
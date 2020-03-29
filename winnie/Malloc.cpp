//
//  Malloc.cpp
//  pooh
//
//  Created by Shaul Fridmsn on 02/12/2019.
//  Copyright © 2019 Yir. All rights reserved.
//

#include "Malloc.hpp"

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
   
#include <malloc/malloc.h>

typedef void * (*MallocFn)(size_t);
typedef void * (*RellocFn)(void *alloc, size_t);
typedef void * (*FreeFn)(void * ptr);

void *malloc(size_t size) {
        void * handle = (void*) -1;
        MallocFn ptr = (MallocFn)dlsym(handle, "malloc");
        if (ptr == NULL) {
                printf("Opps\n");
                exit(1);
        }
        void *alloc = ptr(size);
        printf("Alloc = %p Size: %zu\n", alloc, size);
        return alloc;
}

void *realloc(void *alloc, size_t size) {
        void * handle = (void*) -1;
        RellocFn ptr = (RellocFn) dlsym(handle, "malloc");
        if (ptr == NULL) {
                printf("Opps\n");
                exit(1);
        }
        alloc = ptr(alloc, size);
        printf("Realloc = %p Size: %zu\n", alloc, size);
        return alloc;
}

void free(void *alloc) {
        if (alloc == NULL)
                return;
        printf("free %p\n", alloc);
        void * handle = (void *) -1;
        FreeFn ptr = (FreeFn) dlsym(handle, "free");
        if (ptr == NULL)
                exit(1);

        ptr(alloc);
}

extern "C"
EXPORT void* GetMallocAddress()
{
    return (void*)malloc;
}

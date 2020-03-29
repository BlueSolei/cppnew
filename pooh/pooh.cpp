/*
 *  pooh.cpp
 *  pooh
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "pooh.hpp"
#include "winnie.hpp"

#include <dlfcn.h>
typedef void * (*MallocFn)(size_t);

void*  reallocarray( void* p, size_t count, size_t size )
{
    printf("B: %s\n", __PRETTY_FUNCTION__);
    return NULL;
}
void*  reallocf(void* p, size_t newsize)
{
    printf("B: %s\n", __PRETTY_FUNCTION__);
    return NULL;
}
void   cfree(void* p)
{
    printf("B: %s\n", __PRETTY_FUNCTION__);
}

const char* pathBuff = "/etc/dsaasdddddjdhhdshasdjhdsahjasdhjadshjadsjhadsjhdsajhdsajhasdhjdsahjasd/jhdsa";

void pooh()
{
    void* handle = (void*)-1;
    MallocFn originalMalloc = (MallocFn)dlsym(handle, "malloc");
    printf("originalMalloc: %p\n", originalMalloc);
    MallocFn mallocFnPtr = malloc;
    printf("malloc ptr: %p\n", mallocFnPtr);
    auto p = malloc(21);
    free(p);
//    winnie::something();
    {
      std::string s(pathBuff, pathBuff + strlen(pathBuff));
    }
    printf( "---- begin ----\n" );
    {
        printf( "[1]\n" );
        
        printf( "[2]\n");
        {
            //std::basic_string<char> s(pathBuff, pathBuff + strlen(pathBuff));
            std::string s(pathBuff, pathBuff + strlen(pathBuff));
        }
        
        printf( "[3]\n" );
    }
    
    printf( "---- end ----\n" );
};


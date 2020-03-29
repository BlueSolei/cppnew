//
//  ndsNew.cpp
//  winnie
//

// https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
/// CPP program to demonstrate
// Global overloading of
// new and delete operator
#define _LIBCPP_HAS_NO_BUILTIN_OPERATOR_NEW_DELETE

#include "ndsNew.h"
#include <stdlib.h>
#include <stdio.h>
#include <new>

void * operator new(size_t size)
{
    static unsigned char buffer[1024*1024];
    static unsigned char * ptr = buffer;
//    void * ptr = malloc(size);
    printf( "MainConcept New [%p]\n", ptr );
    
    void * ret = ptr;
    ptr += size;
    return ret;
}

void operator delete(void * ptr) noexcept {
    printf( "MainConcept Delete [%p]\n", ptr );
//    free(ptr);
}

void * operator new[](size_t size)
{
    void * ptr = malloc(size);
    printf( "2.New[] [%p]\n", ptr );
    return ptr;
}

void operator delete ( void * ptr, const std::nothrow_t & _nothrow ) throw ()
{
    printf( "My.1.Delete [%p]\n", ptr );

}

void operator delete[](void * ptr) noexcept
{
    printf( "2.Delete[] [%p]\n", ptr );
    free(ptr);
}

//void operator delete  (void* ptr);
//void operator delete[](void* ptr);
//void operator delete  (void* ptr, const std::nothrow_t& tag);
//void operator delete[](void* ptr, const std::nothrow_t& tag);
//void operator delete  (void* ptr, std::size_t sz);
//void operator delete[](void* ptr, std::size_t sz);

// non-allocating placement allocation functions

//void* operator new( std::size_t size, void* ptr ) noexcept
//{
//    printf( "[5] New operator overloading\n" );
//    return ptr;
//}
//
//void operator delete( void* ptr, void* place ) noexcept
//{
//    printf( "[5] Delete operator overloading\n" );
//}
//
//
//void* operator new[]( std::size_t size, void* ptr ) noexcept
//{
//    printf( "[6] New[] operator overloading\n" );
//    return ptr;
//}
//
//void operator delete[]( void* ptr, void* place ) noexcept
//{
//    printf( "[6] Delete[] operator overloading\n" );
//}


// user-defined placement allocation functions

//void* operator new( std::size_t size, ... )
//{
//    printf( "[7] New operator overloading\n" );
//    void * ptr = malloc(size);
//    return ptr;
//}
//
//void operator delete( void* ptr, ... )
//{
//    printf( "[7] Delete operator overloading\n" );
//    free(ptr);
//}
//
//
//void* operator new[]( std::size_t size, ... )
//{
//    printf( "[8] New operator overloading\n" );
//    void * ptr = malloc(size);
//    return ptr;
//}
//
//void operator delete[]( void* ptr, ... )
//{
//    printf( "[8] Delete operator overloading\n" );
//    free(ptr);
//}

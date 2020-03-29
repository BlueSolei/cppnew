//
//  ndsNew.h
//  winnie
//

#ifndef ndsNew_h
#define ndsNew_h

#include <stdlib.h>

void * operator new(size_t size);
void operator delete(void * ptr) noexcept;
void * operator new[](size_t size);
void operator delete[](void * ptr) noexcept;


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


#endif /* ndsNew_h */

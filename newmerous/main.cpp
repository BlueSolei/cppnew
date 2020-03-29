//
//  main.cpp
//  newmerous
//

#include <iostream>
#include <dlfcn.h>
#include "pooh.hpp"
#include "Malloc.hpp"

void * operator new(size_t size)
{
    static unsigned char buffer[1024*1024];
    static unsigned char * ptr = buffer;
//    void * ptr = malloc(size);
    printf( "App New [%p]\n", ptr );

    void * ret = ptr;
    ptr += size;
    return ret;
}

void operator delete(void * ptr) noexcept {
    printf( "App Delete [%p]\n", ptr );
//    free(ptr);
}
struct S{
    S()
    {
        printf("App: ctor S \n");
    }
    ~S()
    {
        printf("App: dtor S\n");
    }
};

const char* str = "11111111111111111111111111111111111111111111111111111111122222222222222222"
"2222222222222222222222222222222222222222222222222222222222222222222222222222222"
"3333333333333333333333333333333333333333333333333333333333333333333333333333333333333";

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //std::cout << "Malloc Ptr Main: " << GetMallocAddress() << "\n";
    
    void *handle;
    void (*pooh)(void);
    char *error;
    
    handle = dlopen("libpooh.dylib", RTLD_NOW | RTLD_GLOBAL);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    
    dlerror();    /* Clear any existing error */
    
    *(void **) (&pooh) = dlsym(handle, "pooh");
    
    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    
    (*pooh)();
    
    printf("App: string before ctor\n");
    {
        auto len = strlen(str);
        std::string s(str, str + len);
    }
    printf("App: string after dtor\n");

    auto a = new S;
    delete a;
    
    dlclose(handle);
    return 0;
}

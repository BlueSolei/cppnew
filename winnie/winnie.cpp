/*
 *  winnie.cpp
 *  winnie
 *
 *  Created by ykaufman on 11/11/18.
 *  Copyright © 2018 Yir. All rights reserved.
 *
 */
//#define _LIBCPP_HAS_NO_BUILTIN_OPERATOR_NEW_DELETE

#include <iostream>
#include "winnie.hpp"
#include "ndsNew.h"

const char * str = "ajksdjksjfldjfldsjd;flgjfdlkgjfdlskjglfdjgfldjglfdjglsjkdlgjsdjgsldjsfgjfdkgjfsdkjgdkflgjsklfjgkdfjgksjfjgdsklgjdfkjgkdfsjgkdjfgjsdfklgjdkjgksdfjgdjfglsd";

void winnie::something()
{
    {
        struct S{
            S()
            {
                printf("ctor S\n");
            }
            ~S()
            {
                printf("dtor S\n");
            }
        };
        auto p = new S;
        delete p;
        auto m = malloc(21);
        free(m);
    }
    std::cout << "something...\n";
    auto len = strlen(str);
    std::string d(str, str + len);
};

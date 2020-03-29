//
//  Malloc.hpp
//  pooh
//
//  Created by Shaul Fridmsn on 02/12/2019.
//  Copyright © 2019 Yir. All rights reserved.
//

#ifndef Malloc_hpp
#define Malloc_hpp

#include <stdio.h>

#define EXPORT __attribute__((visibility("default")))

extern "C"
EXPORT void* GetMallocAddress();

#endif /* Malloc_hpp */

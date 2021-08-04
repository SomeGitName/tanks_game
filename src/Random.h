#pragma once

#include "time.h"
#include "stdlib.h"

namespace Random
{
    inline void init()
    {
        srand(time(NULL));
    }

    inline int randomInt(int min, int max)
    {
        int r = rand() % (max - min) + min;
        return r;
    }

} 

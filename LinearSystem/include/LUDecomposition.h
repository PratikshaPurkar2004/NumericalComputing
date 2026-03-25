#ifndef LUDECOMPOSITION_H
#define LUDECOMPOSITION_H

#include "LinearSystem.h"

class LUDecomposition : public LinearSystem
{
    public:
        LUDecomposition(int sz);
};

#endif
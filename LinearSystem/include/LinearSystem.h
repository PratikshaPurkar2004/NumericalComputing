#ifndef LINEARSYSTEM_H
#define LINEARSYSTEM_H

# include "Matrix.h"
#include <vector>

class LinearSystem:public Matrix
{
    public:
        LinearSystem(int sz);
        virtual ~LinearSystem() {}
        virtual vector<double> solve() { throw "solve() not implemented"; }
};
#endif
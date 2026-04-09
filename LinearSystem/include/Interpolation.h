#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <fstream>
using namespace std;

#include "Matrix.h"

class Interpolation : public Matrix
{
    public:
        Interpolation(int n1 = 0);
        //void setPoint(int i, double xi, double yi); 
        virtual double solve(double xp) = 0;
};

#endif
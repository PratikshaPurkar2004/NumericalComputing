#ifndef LAGRANGE_H
#define LAGRANGE_H

#include "Interpolation.h"

class Lagrange : public Interpolation
{
public:
    Lagrange(int n1=0);

    double solve(double xp);
};

#endif
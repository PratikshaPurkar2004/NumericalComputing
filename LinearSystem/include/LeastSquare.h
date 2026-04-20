#ifndef LEASTSQUARE_H
#define LEASTSQUARE_H

#include "CurveFitting.h"

class LeastSquare : public CurveFitting
{
public:
    LeastSquare(int n);
    void fit(ofstream &fout);
};

#endif
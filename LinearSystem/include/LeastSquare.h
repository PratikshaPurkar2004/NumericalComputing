#ifndef LEASTSQUARE_H
#define LEASTSQUARE_H

#include "CurveFitting.h"
#include <fstream>

class LeastSquare : public CurveFitting
{
public:
    LeastSquare(int n);

    void fitPolynomial(std::ofstream &fout, int degree);
};

#endif
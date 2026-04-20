#ifndef CURVEFITTING_H
#define CURVEFITTING_H

#include "Matrix.h"
#include <fstream>
using namespace std;

class CurveFitting : public Matrix
{
public:
    CurveFitting(int n);

    void readPoints(ifstream &fin);
    int size() const;
};

#endif
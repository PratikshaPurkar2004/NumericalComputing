#ifndef GERSCHGORIN_H
#define GERSCHGORIN_H

#include "Eigen.h"

class Gerschgorin : public Eigen
{
public:
    Gerschgorin(int n = 0);
    void findDiscs(ofstream &fout, double tol = 1e-6); 
};

#endif
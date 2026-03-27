#ifndef JACOBI_H
#define JACOBI_H

#include "Matrix.h"
#include<vector>
using namespace std;

class Jacobi : public Matrix
{
public:
    Jacobi(int n) : Matrix(n,n+1) {}

    vector<double> solve(int maxIter = 100, double tol = 1e-6);
};

#endif
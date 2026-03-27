#ifndef SEIDEL_H
#define SEIDEL_H

#include "Matrix.h"
#include<vector>
using namespace std;

class Seidel : public Matrix
{
public:
    Seidel(int n) : Matrix(n,n+1) {}

    vector<double> solve(int maxIter = 100, double tol = 1e-6);
};

#endif
#ifndef JACOBI_H
#define JACOBI_H

#include "Iteration.h"
#include "Matrix.h"
#include<vector>
using namespace std;

class Jacobi : public Iteration
{
public:
    Jacobi(int n) : Iteration(n) {}
    vector<double> solve(int maxIter = 100, double tol = 1e-6);
};

#endif
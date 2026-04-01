#ifndef SEIDEL_H
#define SEIDEL_H

#include "Iteration.h"
#include "Matrix.h"
#include<vector>
using namespace std;

class Seidel : public Iteration
{
public:
    Seidel(int n) : Iteration(n) {}

    vector<double> solve(int maxIter = 100, double tol = 1e-6);
};

#endif
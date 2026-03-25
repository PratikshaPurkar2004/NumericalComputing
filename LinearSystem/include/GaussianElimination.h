#ifndef GAUSSIANELIMINATION_H
#define GAUSSIANELIMINATION_H

#include<vector>
#include "LinearSystem.h"
using namespace std;

class GaussianElimination:public LinearSystem
{
    public:
        GaussianElimination(int sz);
        virtual void pivot(int k)=0;
        virtual vector<double> solve() = 0;
        void forwardElimination();
        vector<double>backSubstitution(); 
};

class withoutPivot:public GaussianElimination
{
    public:
        withoutPivot(int sz);
        void pivot(int k)override;
        vector<double> solve() override;
};

class partialPivot:public GaussianElimination
{
    public:
        partialPivot(int sz);
        void pivot(int k)override;
        vector<double> solve() override;
};
#endif
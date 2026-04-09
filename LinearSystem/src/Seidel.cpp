#include "Seidel.h"
#include <cmath>
#include <iostream>

vector<double> Seidel::solve(int maxIter, double tol)
{
    int n = rows;

    // if(!isDiagonallyDominant())
    // {
    //     cout<<"Matrix not diagonally dominant ";
    //     makeDiagonallyDominant();
    // }

    vector<double> x(n,0);

    for(int iter=0; iter<maxIter; iter++)
    {
        vector<double> old = x;

        for(int i=0;i<n;i++)
        {
            if((*this)(i,i)==0)
                throw "Zero diagonal in Seidel";

            double sum = (*this)(i,n);

            for(int j=0;j<n;j++)
                if(i!=j)
                    sum -= (*this)(i,j)*x[j];

            x[i] = sum / (*this)(i,i);
        }

        double err = 0;
        for(int i=0;i<n;i++)
            err += fabs(x[i]-old[i]);

        if(err < tol)
            return x;
    }

    return x;
}
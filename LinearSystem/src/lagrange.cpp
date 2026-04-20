#include "Lagrange.h"

Lagrange::Lagrange(int n1) : Interpolation(n1) {}

double Lagrange::solve(double xp)
{
    if(rows == 0)
        throw "No data points";

    double yp = 0;

    for(int i = 0; i < rows; i++)
    {
        double L = 1;

        for(int j = 0; j < rows; j++)
        {
            if(i != j)
            {
                if((*this)(i,0) == (*this)(j,0))
                    throw "duplicate x values";

                L *= (xp - (*this)(j,0)) /
                     ((*this)(i,0) - (*this)(j,0));
            }
        }

        yp += L * (*this)(i,1);
    }

    return yp;
}
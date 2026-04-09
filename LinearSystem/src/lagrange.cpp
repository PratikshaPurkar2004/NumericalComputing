#include "Lagrange.h"

Lagrange::Lagrange(int n1) : Interpolation(n1) {}

double Lagrange::solve(double xp)
{
    double yp = 0;

    for(int i = 0; i < rows; i++)
    {
        double L = 1;

        for(int j = 0; j < rows; j++)
        {
            if(i != j)
            {
                if(a[i][0] == a[j][0])
                    throw "duplicate x values";

                L *= (xp - a[j][0]) / (a[i][0] - a[j][0]);
            }
        }

        yp += L * a[i][1];
    }

    return yp;
}
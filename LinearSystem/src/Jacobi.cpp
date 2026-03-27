// #include "Jacobi.h"
// #include <cmath>
// #include <iostream>

// vector<double> Jacobi::solve(int maxIter, double tol)
// {
//     int n = rows;

//     vector<double> x(n,0), x_new(n,0);

//     for(int iter=0; iter<maxIter; iter++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             if((*this)(i,i)==0)
//                 throw "Zero diagonal in Jacobi";

//             double sum = (*this)(i,n);

//             for(int j=0;j<n;j++)
//                 if(i!=j)
//                     sum -= (*this)(i,j)*x[j];

//             x_new[i] = sum / (*this)(i,i);
//         }

//         double err = 0;
//         for(int i=0;i<n;i++)
//             err += fabs(x_new[i]-x[i]);

//         if(err < tol)
//             return x_new;

//         x = x_new;
//     }

//     return x;
// }

#include "Jacobi.h"
#include <cmath>
#include <iostream>

vector<double> Jacobi::solve(int maxIter, double tol)
{
    int n = rows;

    vector<double> x(n, 0), x_new(n, 0);

    double w = 0.5;   // RELAXATION FACTOR 

    for(int iter = 0; iter < maxIter; iter++)
    {
        for(int i = 0; i < n; i++)
        {
            if((*this)(i,i) == 0)
            {
                cout<<"Warning: zero diagonal at row "<<i<<"\n";
                x_new[i] = x[i];
                continue;
            }

            double sum = (*this)(i,n);

            for(int j = 0; j < n; j++)
            {
                if(i != j)
                    sum -= (*this)(i,j) * x[j];
            }

            double xi = sum / (*this)(i,i);

            // RELAXATION (prevents explosion)
            x_new[i] = (1 - w) * x[i] + w * xi;
        }

        // error calculation
        double err = 0;
        for(int i = 0; i < n; i++)
            err += fabs(x_new[i] - x[i]);

        if(err < tol)
            return x_new;

        x = x_new;
    }
    return x;
}
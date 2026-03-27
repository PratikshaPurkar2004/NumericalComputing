#include<iostream>
#include<vector>
#include<cmath>
#include "Cholesky.h"
using namespace std;

Cholesky::Cholesky(int sz):LUDecomposition(sz)
{}

vector<double> Cholesky::solve()
{
    int n=rows;

    if(!isSymetric())
        throw "Matrix not symmetric";

    vector<vector<double>> L(n,vector<double>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            double sum=0;
            for(int k=0;k<j;k++)
                sum+=L[i][k]*L[j][k];

            if(i==j)
            {
                if(a[i][i]-sum <= 0)
                    throw "Matrix not positive definite";

                L[i][j]=sqrt(a[i][i]-sum);
            }
            else
            {
                if(L[j][j]==0)
                    throw "Division by zero in Cholesky";

                L[i][j]=(a[i][j]-sum)/L[j][j];
            }
        }
    }

    vector<double> y(n), x(n);

    // Ly = b
    for(int i=0;i<n;i++)
    {
        y[i]=a[i][n];
        for(int j=0;j<i;j++)
            y[i]-=L[i][j]*y[j];

        if(L[i][i]==0)
            throw "Division by zero";

        y[i]/=L[i][i];
    }

    // L^T x = y
    for(int i=n-1;i>=0;i--)
    {
        x[i]=y[i];
        for(int j=i+1;j<n;j++)
            x[i]-=L[j][i]*x[j];

        if(L[i][i]==0)
            throw "Division by zero";

        x[i]/=L[i][i];
    }

    return x;
}
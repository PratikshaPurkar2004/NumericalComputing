#include<iostream>
#include "Doolittle.h"
#include<vector>
using namespace std;

Doolittle::Doolittle(int sz):LUDecomposition(sz)
{}

vector<double> Doolittle::solve()
{
    int n=rows;
    vector<vector<double>> L(n,vector<double>(n,0));
    vector<vector<double>> U(n,vector<double>(n,0));

    for(int i=0;i<n;i++)
        L[i][i]=1;

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=j;i++)
        {
            double sum=0;
            for(int k=0;k<i;k++)
                sum+=L[i][k]*U[k][j];

            U[i][j]=a[i][j]-sum;
        }

        for(int i=j+1;i<n;i++)
        {
            double sum=0;
            for(int k=0;k<j;k++)
                sum+=L[i][k]*U[k][j];

            if(U[j][j]==0)
                throw "Zero pivot in Doolittle";

            L[i][j]=(a[i][j]-sum)/U[j][j];
        }
    }

    vector<double> y(n), x(n);

    // Forward substitution (Ly = b)
    for(int i=0;i<n;i++)
    {
        y[i]=a[i][n];
        for(int j=0;j<i;j++)
            y[i]-=L[i][j]*y[j];
    }

    // Back substitution (Ux = y)
    for(int i=n-1;i>=0;i--)
    {
        x[i]=y[i];
        for(int j=i+1;j<n;j++)
            x[i]-=U[i][j]*x[j];

        if(U[i][i]==0)
            throw "Division by zero in Doolittle";

        x[i]/=U[i][i];
    }

    return x;
}
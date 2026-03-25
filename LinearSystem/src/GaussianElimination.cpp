#include<iostream>
#include<cmath>
#include "GaussianElimination.h"
using namespace std;

GaussianElimination::GaussianElimination(int sz) : LinearSystem(sz)
{}

vector<double>partialPivot::solve()
{
    forwardElimination();
    return backSubstitution();
}

vector<double> withoutPivot::solve()
{
    forwardElimination();
    return backSubstitution();
}

void GaussianElimination::forwardElimination()
{
    for(int k=0;k<rows;k++)
    {
        pivot(k);
        if(fabs(a[k][k]) < 1e-12)
            throw "zero pivot";
        for(int i=k+1;i<rows;i++)
        {
            double factor=a[i][k]/a[k][k];
            for(int j=k;j<cols;j++)
                a[i][j]-=factor*a[k][j];
        }

    }
}

vector<double> GaussianElimination::backSubstitution()
{
    vector <double>x(rows);
    for(int i=rows-1;i>=0;i--)
    {
        x[i]=a[i][cols-1];
        for(int j=i+1;j<rows;j++)
            x[i]-=a[i][j]*x[j];
        x[i]/=a[i][i];
    }
    return x;
}

withoutPivot::withoutPivot(int sz):GaussianElimination(sz)
{}

void withoutPivot::pivot(int k)
{}

partialPivot::partialPivot(int sz):GaussianElimination(sz)
{}

void partialPivot::pivot(int k)
{
    int maxRow=k;
    for(int i=k+1;i<rows;i++)
    {
        if(fabs(a[i][k])>fabs(a[maxRow][k]))
            maxRow=i;
    }
    if(maxRow!=k)
        swap(a[k],a[maxRow]);
}
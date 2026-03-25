#include<iostream>
#include "Doolittle.h"
#include<vector>
using namespace std;

Doolittle::Doolittle(int sz):LUDecomposition(sz)
{}

// void Doolittle:: decompose(ofstream &fout)
// {
//     int n=rows;
//     vector<vector<double>>L(n,vector<double>(n,0));
//     vector<vector<double>>U(n,vector<double>(n,0));
//     for(int i=0;i<n;i++)
//         L[i][i]=1;
//     for(int j=0;j<n;j++)
//     {
//         for(int i=0;i<=j;i++)
//         {
//             double sum=0;
//             for(int k=0;k<i;k++)
//                 sum+=L[i][k]*U[k][j];
//             U[i][j]=a[i][j]-sum;
//         }
//         for(int i=j+1;i<n;i++)
//         {
//             double sum=0;
//             for(int k=0;k<j;k++)
//                 sum+=L[i][k]*U[k][j];
//             L[i][j]=(a[i][j]-sum)/U[j][j];
//         }
//     }
//     fout<<"\n Doolittle L matrix is:"<<endl;
//     for(auto &row:L)
//     {
//         for(auto & val:row)
//             fout<<val<<" ";
//         fout<<endl;
//     }
//     fout<<"\n Doolittle U matrix is:"<<endl;
//     for(auto &row:U)
//     {
//         for(auto & val:row)
//             fout<<val<<" ";
//         fout<<endl;
//     }
// }


vector<double> Doolittle::solve()
{
    int n=rows;
    vector<vector<double>>L(n,vector<double>(n,0));
    vector<vector<double>>U(n,vector<double>(n,0));

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
            L[i][j]=(a[i][j]-sum)/U[j][j];
        }
    }

    // Forward substitution
    vector<double> y(n), x(n);
    for(int i=0;i<n;i++)
    {
        y[i]=a[i][n];
        for(int j=0;j<i;j++)
            y[i]-=L[i][j]*y[j];
    }

    // Back substitution
    for(int i=n-1;i>=0;i--)
    {
        x[i]=y[i];
        for(int j=i+1;j<n;j++)
            x[i]-=U[i][j]*x[j];
        x[i]/=U[i][i];
    }

    return x;
}
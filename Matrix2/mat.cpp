#include<iostream>
#include<cmath>
using namespace std;
#include "mat.hpp"

Matrix::Matrix(int rows,int cols)
{
    this->rows=rows; 
    this->cols=cols;
}

Matrix::Matrix(const Matrix &m)
{
    this->rows=m.rows;
    this->cols=m.cols;
}

    void Matrix::input()
    {
        cout<<"enter first matrix elements::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cin>>m1[i][j];
            cout<<endl;
        }

        cout<<"enter second matrix elements::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cin>>m2[i][j];
            cout<<endl;
        }
    }

    void Matrix::printMatrix()
    {
        cout<<"first matrix is::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cout<<m1[i][j]<<" ";
            cout<<endl;
        }
        cout<<"second matrix is::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cout<<m2[i][j]<<" ";
            cout<<endl;
        }
    }

    void Matrix::addition()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                add_ans[i][j]=m1[i][j]+m2[i][j];
        }
        cout<<"addition of two matrices is::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cout<<add_ans[i][j]<<" ";
            cout<<endl;
        }
       
    }

     void Matrix::subtraction()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                sub_ans[i][j]=m1[i][j]-m2[i][j];
        }
        cout<<"subtraction of two matrices is::\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cout<<sub_ans[i][j]<<" ";
            cout<<endl;
        }

    }

void Matrix::GaussianElimination()
{
    try
    {
        for(int k=0;k<rows-1;k++)
        {
            partialPivot(k);
            if(m1[k][k]==0)
                throw "pivoit element is zero";
            for(int i=k+1;i<rows;i++)
            {
                double factor=m1[i][k]/m1[k][k];
                for(int j=k;j<cols;j++)
                    m1[i][j]=m1[i][j]-factor*m1[k][j];
            }
        }
         cout<<"\nUpper Triangular Matrix:\n";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                cout<<m1[i][j]<<" ";
            cout<<endl;
        }
    }
    catch(const char* msg)
    {
        cout<<"Error: "<<msg<<endl;
    }
}

void Matrix::backSubstitution()
{
    try
    {
        double x[100];
        for(int i=rows-1;i>=0;i--)
        {
            x[i]=m1[i][cols-1];
            for(int j=i+1;j<rows;j++)
                x[i]=x[i]-m1[i][j]*x[j];

            if(m1[i][i]==0)
                throw "no solution exists";
        
            x[i]=x[i]/m1[i][i];
        }
        cout<<"\nSolution is:\n";
        for(int i=0;i<rows;i++)
            cout<<"x"<<i+1<<" = "<<x[i]<<endl;
    }
    catch(const char* msg)
    {
        cout<<"Error: "<<msg<<endl;
    }
}

void Matrix::partialPivot(int k)
{
    int maxRow=k;
    for(int i=k+1;i<rows;i++)
    {
        if(fabs(m1[i][k])>fabs(m1[maxRow][k]))
            maxRow=i;
    }
    if(maxRow!=k)
    {
        for(int j=0;j<cols;j++)
        {
            double temp=m1[k][j];
            m1[k][j]=m1[maxRow][j];
            m1[maxRow][j]=temp;
        }
    }
}


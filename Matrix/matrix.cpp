#include<iostream>
using namespace std;
#include "matrix.hpp"

Matrix::Matrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
}

Matrix::Matrix(const Matrix &m)
{
    this->rows=m.rows;
    this->cols=m.cols;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            this->mat[i][j]=m.mat[i][j];
    }
}

void Matrix::input()
{
    cout<<"Enter the matrix: "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cin>>mat[i][j];
        cout<<endl;
    }

}

void Matrix::display()
{
    cout<<"The matrix is: "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void Matrix::addition(Matrix &m2)
{
    cout<<"The addition of the two matrices is: "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<mat[i][j]+m2.mat[i][j]<<" ";
        cout<<endl;
    }
}


void Matrix::subtraction(Matrix &m2)
{
    cout<<"The subtraction of the two matrices is: "<<endl;
    for(int i=0;i<rows;i++)         
    {
        for(int j=0;j<cols;j++)
            cout<<mat[i][j]-m2.mat[i][j]<<" ";
        cout<<endl;
    }
}

void Matrix::GaussianElimination()
{
    for(int k=0;k<rows-1;k++)
    {
        if(mat[k][k]==0)
        {
            cout<<"zero pivot element";
            return;
        }
        for(int i=k+1;i<rows;i++)
        {
            double factor=mat[i][k]/mat[k][k];
            for(int j=k;j<cols;j++)
                mat[i][j]=mat[i][j]-factor*mat[k][j];
        }
    }
    cout<<"The upper triangular matrix is: "<<endl;
    for(int i=0;i<rows;i++)        
    {
        for(int j=0;j<cols;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}


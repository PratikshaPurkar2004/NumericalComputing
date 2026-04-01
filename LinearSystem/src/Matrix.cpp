// #include<iostream>
#include<cmath>
// #include <fstream>
#include "Matrix.h"
//using namespace std;

Matrix::Matrix()
{
    rows=cols=0;
}

Matrix::Matrix(int r,int c)
{
    rows=r;
    cols=c;
    a.resize(rows,vector<double>(cols,0));
}

Matrix::Matrix(const Matrix &m)
{
    rows=m.rows;
    cols=m.cols;
    a=m.a;
}

void Matrix::resize(int r,int c)
{
    rows = r;
    cols = c;
    a.assign(rows, vector<double>(cols, 0));
}

// Matrix::~Matrix()
// {}

void Matrix::readFromFile(ifstream &fin)
{
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            fin >> a[i][j];
}

void Matrix::displayToFile(ofstream &fout)const
{
    cout<<"solution\n";
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            fout<<a[i][j] <<" ";
        fout<<endl;
    }
}

Matrix Matrix::operator+(const Matrix &m)const
{
    if(rows!=m.rows || cols!=m.cols)
        throw "Matrix size mismatch"; 
    Matrix sum(rows,cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            sum.a[i][j] = a[i][j] + m.a[i][j];
    }
    return sum;
}

Matrix Matrix::operator-(const Matrix& m)const
{
    if(rows!=m.rows || cols!=m.cols)
        throw "Matrix size mismatch";
    Matrix subtract(rows,cols);
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            subtract.a[i][j] = a[i][j] - m.a[i][j];
    }
    return subtract;
}

Matrix Matrix::operator*(const Matrix &m)const
{
    if(cols != m.rows)
        throw "Matrix size mismatch";
    Matrix mul(rows,m.cols);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<m.cols;j++)
            for(int k=0;k<cols;k++)
                mul.a[i][j]+=a[i][k]*m.a[k][j];
    }
    return mul;
}

double &Matrix::operator()(int i,int j)
{
    return a[i][j];
}

double Matrix::operator()(int i,int j)const
{
    return a[i][j];
}

bool Matrix::operator==(const Matrix &m)const
{
    if(rows!=m.rows || cols!=m.cols)
        return false;
    
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]!=m.a[i][j])
                return false;
    return true;
}

istream &operator>>(istream &in,Matrix &m)
{
    for(int i=0;i<m.rows;i++)
        for(int j=0;j<m.cols;j++)
            in>>m.a[i][j];
    return in;
}

ostream &operator<<(ostream &out,const Matrix &m)
{
    for(int i=0;i<m.rows;i++)
    {
        for(int j=0;j<m.cols;j++)
            out<<m.a[i][j] <<" ";
        out<<endl;
    }
    return out;
}

bool Matrix::isSquare()const
{
    return rows==cols;
}

bool Matrix::isSymetric()const
{
    if(!isSquare())
        return false;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]!=a[j][i])
                return false;
    return true;
}

bool Matrix::isIdentity()const
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==j && a[i][j]!=1)
                return false;
            if(i!=j && a[i][j]!=0)
                return false;
        }
    }
    return true;
}

bool Matrix::isNull()const
{
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]!=0)
                return false;
    return true;
}

bool Matrix::isDiagonal()const
{
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(i!=j && a[i][j]!=0)
                return false;
    return true;
}

bool Matrix::isDiagonallyDominant()const
{
    for(int i=0;i<rows;i++)
    {
        double sum=0.0;
        for(int j=0;j<rows;j++)
        {
            if(i!=j)
                sum+=abs(a[i][j]);
        }
        if(abs(a[i][i])<=sum)
            return false;
    }
    return true;
}

bool Matrix::isTranspose(const Matrix &m)const
{
    if(rows!=m.cols || cols!=m.rows)
        return false;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(a[i][j]!=m.a[j][i])
                return false;
    return true;
}

Matrix Matrix::transpose()const
{
    Matrix t(cols,rows);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            t.a[j][i]=a[i][j];
    return t;
}

void Matrix:: makeDiagonallyDominant()
{
    for(int i=0;i<rows;i++)
    {
        int maxRow=i;
        for(int k=i+1;k<rows;k++)
            if(abs(a[k][i])>abs(a[maxRow][i]))
                maxRow=k;
        swap(a[i],a[maxRow]);
    }
}

// double Matrix::determinant()const
// {
//     if(rows==1)
//         return a[0][0];
//     if(rows==2)
//         return a[0][0]*a[1][1]-a[0][1]*a[1][0];

//     double det=0;
//     for(int p=0;p<cols;p++)
//     {
//         Matrix sub(rows-1,cols-1);
//         for(int i=1;i<rows;i++)
//         {
//             int colIndex=0;
//             for(int j=0;j<cols;j++)
//             {
//                 if(j==p)
//                     continue;
//                 sub.a[i-1][colIndex]=a[i][j];
//                 colIndex++;
//             }
//         }
//         if(p%2==0)
//             det+=a[0][p]*sub.determinant();
//         else
//             det-=a[0][p]*sub.determinant();
//     }
//     return det;
// }

double Matrix::determinant() const
{
    if(rows!=cols)
        throw "Matrix must be square";

    Matrix temp(*this);
    double det=1;

    for(int k=0;k<rows;k++)
    {
        if(fabs(temp.a[k][k])<0)
            return 0;

        for(int i=k+1;i<rows;i++)
        {
            double factor=temp.a[i][k]/temp.a[k][k];

            for(int j=k;j<rows;j++)
                temp.a[i][j]-=factor*temp.a[k][j];
        }
    }

    for(int i=0;i<rows;i++)
        det*= temp.a[i][i];

    return det;
}

Matrix Matrix::inverse()const
{
    if(rows!=cols)
        throw "Inverse only for square matrix";
        //int n=rows;
    Matrix inv(rows,cols);
    Matrix temp(*this);
    for(int i=0;i<rows;i++)
        inv.a[i][i]=1;
    for(int i=0;i<rows;i++)
    {
        double pivot=temp.a[i][i];
        if(pivot==0)
            throw "Matrix is singular";

        for(int j=0;j<rows;j++)
        {
            temp.a[i][j]/=pivot;
            inv.a[i][j]/=pivot;
        }
        for(int k=0;k<rows;k++)
        {
            if(k==i)
                continue;
            double factor=temp.a[k][i];
            for(int j=0;j<cols;j++)
            {
                temp.a[k][j]-=factor*temp.a[i][j];
                inv.a[k][j]-=factor*inv.a[i][j];
            }
        }
    }
    return inv;
}





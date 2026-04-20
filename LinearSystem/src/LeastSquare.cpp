#include "LeastSquare.h"
#include <iostream>
using namespace std;

LeastSquare::LeastSquare(int n) : CurveFitting(n) {}

void LeastSquare::fit(ofstream &fout)
{
    int n = size();

    Matrix X(n, 2);
    Matrix Y(n, 1);

    for(int i = 0; i < n; i++)
    {
        X(i,0) = 1;
        X(i,1) = (*this)(i,0);
        Y(i,0) = (*this)(i,1);
    }

    Matrix Xt = X.transpose();
    Matrix A = (Xt * X).inverse() * Xt * Y;

    fout << "\nLeast Square Line:\n";
    fout << "y = a + b*x\n";
    fout << "a = " << A(0,0) << endl;
    fout << "b = " << A(1,0) << endl;

    cout << "\nLeast Square Line:\n";
    cout << "a = " << A(0,0) << "  b = " << A(1,0) << endl;
}
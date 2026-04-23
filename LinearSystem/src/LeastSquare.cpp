#include "LeastSquare.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

LeastSquare::LeastSquare(int n) : CurveFitting(n) {}

void LeastSquare::fitPolynomial(ofstream &fout, int degree)
{
    int n = size();

    if(degree >= n)
        throw "Degree must be less than number of points";

    Matrix X(n, degree + 1);
    Matrix Y(n, 1);

    for(int i = 0; i < n; i++)
    {
        double x = (*this)(i,0);
        double y = (*this)(i,1);

        for(int j = 0; j <= degree; j++)
        {
            X(i,j) = pow(x, j);
        }

        Y(i,0) = y;
    }

    Matrix Xt = X.transpose();
    Matrix A = (Xt * X).inverse() * Xt * Y;

    fout << fixed << setprecision(4);

    fout << "\n POLYNOMIAL FIT \n";
    fout << "Degree = " << degree << endl;

    fout << "y = ";
    for(int i = 0; i <= degree; i++)
    {
        double coeff = A(i,0);

        if(i == 0)
        {
            fout << coeff;
        }
        else
        {
            if(coeff >= 0)
                fout << " + " << coeff << "x^" << i;
            else
                fout << " - " << fabs(coeff) << "x^" << i;
        }
    }
    fout << endl;

    double sumErrorSq = 0;

    for(int i = 0; i < n; i++)
    {
        double x = (*this)(i,0);
        double y = (*this)(i,1);

        double yhat = 0;

        for(int j = 0; j <= degree; j++)
        {
            yhat += A(j,0) * pow(x, j);   
        }

        double err = y - yhat;
        sumErrorSq += err * err;
    }

    double rms = sqrt(sumErrorSq / n);

    fout << "\nRMS Error = " << rms << endl;
}
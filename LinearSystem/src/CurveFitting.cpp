#include "CurveFitting.h"

CurveFitting::CurveFitting(int n) : Matrix(n, 2) {}

void CurveFitting::readPoints(ifstream &fin)
{
    for(int i = 0; i < rows; i++)
    {
        fin >> (*this)(i,0) >> (*this)(i,1);
    }
}

int CurveFitting::size() const
{
    return rows;
}
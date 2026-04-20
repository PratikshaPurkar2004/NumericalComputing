#include "Interpolation.h"

Interpolation::Interpolation(int n1) : Matrix(n1, 2)
{}

void Interpolation::readPoints(ifstream &fin)
{
    for(int i = 0; i < rows; i++)
    {
        fin >> (*this)(i,0) >> (*this)(i,1);
    }
}

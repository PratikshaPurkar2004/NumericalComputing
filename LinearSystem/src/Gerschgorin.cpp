#include "Gerschgorin.h"
#include<cmath>

Gerschgorin::Gerschgorin(int n) : Eigen(n) {}

void Gerschgorin::findDiscs(ofstream &fout, double tol)
{
    for(int i = 0; i < rows; i++)
    {
        double center = a[i][i];
        double radius = 0;

        for(int j = 0; j < cols; j++)
        {
            if(i != j && fabs(a[i][j]) > tol)   
                radius += fabs(a[i][j]);
        }

        fout << "Disc " << i+1
             << ": |z - " << center
             << "| <= " << radius << endl;
        fout << "Approx Eigenvalue ≈ " << center << endl << endl;
    }
}


#include "Gerschgorin.h"
#include <cmath>
#include <iomanip>   // for formatting
using namespace std;

Gerschgorin::Gerschgorin(int n) : Eigen(n) {}

void Gerschgorin::findDiscs(ofstream &fout, double tol)
{
    fout << "\n========== GERSCHGORIN DISCS ==========\n\n";

    fout << fixed << setprecision(4);   // control decimal places

    for(int i = 0; i < rows; i++)
    {
        double center = (*this)(i,i);
        double radius = 0;

        for(int j = 0; j < cols; j++)
        {
            if(i != j && fabs((*this)(i,j)) > tol)
                radius += fabs((*this)(i,j));
        }

        fout << "Disc " << setw(3) << i+1 << ":\n";
        fout << "----------------------------------\n";
        fout << "Center (a[" << i+1 << "," << i+1 << "]) : "
             << setw(10) << center << endl;

        fout << "Radius                        : "
             << setw(10) << radius << endl;

        fout << "Region: |z - (" << center << ")| <= " << radius << endl;

        fout << "Approx Eigenvalue             : "
             << center << endl;

        fout << "----------------------------------\n\n";
    }

    fout << "=======================================\n";
}
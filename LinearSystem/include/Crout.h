#ifndef CROUT_H
#define CROUT_H

#include "LUDecomposition.h"

class Crout : public LUDecomposition
{
    public:
        Crout (int sz);
        vector<double> solve();  
        //void decompose(ofstream &fout);
};

#endif
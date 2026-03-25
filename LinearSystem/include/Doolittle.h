#ifndef DOOLITTLE_H
#define DOOLITTLE_H

#include "LUDecomposition.h"

class Doolittle:public LUDecomposition
{
    public:
        Doolittle(int sz);
        vector<double> solve();  
        //void decompose(ofstream &fout);
};
#endif
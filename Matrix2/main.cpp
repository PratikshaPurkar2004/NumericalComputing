#include<iostream>
using namespace std;
#include "mat.hpp"
int main()
{
    int rows,cols;
   // double m1[100][100],m2[100][100],add_ans[100][100],sub_ans[100][100];
    
    cout<<"enter rows::\n";
    cin>>rows;
    cout<<"enter cols::\n";
    cin>>cols;
    
    Matrix m(rows,cols);
    
    m.input();
    m.printMatrix();
    m.addition();
    m.subtraction();
    m.GaussianElimination();
    m.backSubstitution();
    
    
    return 0;
}

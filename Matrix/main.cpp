#include<iostream>
using namespace std;
#include "matrix.hpp"

int main()
{
    int rows,cols;

    cout<<"enter rows::"<<"\n";
    cin>>rows;
    
    cout<<"enter cols::"<<"\n";
    cin>>cols;
    
    Matrix m1(rows,cols);
    m1.input();
    m1.display();
   
    Matrix m2=m1;
  
    m1.addition(m2);
    m1.subtraction(m2);
    m2.GaussianElimination();
    return 0;   
} 
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include<iostream>
#include<fstream>
using namespace std;

class Matrix{
    protected:
        int rows ,cols ;
        vector<vector<double>>a;

    public:
        Matrix();
        Matrix(int rows,int cols);
        Matrix(const Matrix &m);
        void readFromFile(ifstream &fin);
        void displayToFile(ofstream &fout) const;
        Matrix operator+(const Matrix &m)const;
        Matrix operator-(const Matrix &m)const;
        Matrix operator*(const Matrix &m)const;
        double &operator()(int i,int j);
        double operator()(int i,int j)const;
        bool operator==(const Matrix &m)const;
        friend istream &operator>>(istream &in ,Matrix &m);
        friend ostream &operator<<(ostream &out,const Matrix &m);
        bool isSquare()const;
        bool isSymetric()const;
        bool isIdentity()const;
        bool isNull()const;
        bool isDiagonal()const;
        bool isTranspose(const Matrix &m)const;
        bool isDiagonallyDominant()const;
        void makeDiagonallyDominant();
        Matrix transpose()const;
        double determinant()const;
        Matrix inverse()const;
};

#endif
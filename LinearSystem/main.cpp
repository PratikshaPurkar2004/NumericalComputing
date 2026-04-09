#include<iostream>
#include<fstream>
#include<vector>

#include "GaussianElimination.h"
#include "Crout.h"
#include "Doolittle.h"
#include "Cholesky.h"
#include "Jacobi.h"
#include "Seidel.h"
#include "Gerschgorin.h"
#include "Lagrange.h"   

using namespace std;

int main()
{
    ifstream leftFile("49/49l.txt");   
    ifstream rightFile("49/49r.txt");
    ofstream fout("output.txt");

    if(!leftFile || !rightFile || !fout)
    {
        cout<<"File error\n";
        return 1;
    }

    int choice;
    cout<<"\n1. Gaussian\n2. Doolittle\n3. Crout\n4. Cholesky\n5. Jacobi\n6. Seidel\n7. Lagrange\n";
    cout<<"Enter choice: ";
    cin>>choice;

    int r,c;
    leftFile >> r >> c;

    
    Gerschgorin g(r);
    g.readFromFile(leftFile);

    fout << "\nGerschgorin Discs\n";
    g.findDiscs(fout);
    fout << "Choice = " << choice << "\n";


    leftFile.clear();
    leftFile.seekg(0);
    leftFile >> r >> c;

    LinearSystem* solver;

    if(choice == 1)
        solver = new partialPivot(r);
    else if(choice == 2)
        solver = new Doolittle(r);
    else if(choice == 3)
        solver = new Crout(r);
    else if(choice == 4)
        solver = new Cholesky(r);

    else if(choice == 5)
    {
        Jacobi jb(r);

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                leftFile >> jb(i,j);

        for(int i=0;i<r;i++)
            rightFile >> jb(i,c);

        try
        {
            vector<double> x = jb.solve(1000,0.000001);

            fout<<"Jacobi Solution\n";
            for(int i=0;i<r;i++)
                fout<<"x"<<i+1<<" = "<<x[i]<<endl;
        }
        catch(const char* msg)
        {
            cout<<"Error: "<<msg<<endl;
            fout<<"Error: "<<msg<<endl;
        }
        return 0;
    }

    else if(choice == 6)
    {
        Seidel sd(r);

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                leftFile >> sd(i,j);

        for(int i=0;i<r;i++)
            rightFile >> sd(i,c);

        vector<double> x = sd.solve(1000,0.000001);

        fout<<"Seidel Solution\n";
        for(int i=0;i<r;i++)
            fout<<"x"<<i+1<<" = "<<x[i]<<endl;

        return 0;
    }

    else if(choice == 7)
    {
        ifstream fin("points.txt");

        if(!fin)
        {
            cout<<"Points file error\n";
            return 0;
        }

        int n;
        fin >> n;

        Lagrange lg(n);
        lg.readPoints(fin);

        double xp;
        cout<<"Enter value to interpolate: ";
        cin>>xp;

        double result = lg.solve(xp);

        fout<<"Lagrange Interpolation\n";
        fout<<"Value at x = "<<xp<<" is "<<result<<endl;

        return 0;
    }

    else
    {
        cout<<"Invalid choice\n";
        return 0;
    }

    solver->resize(r, c + 1);

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            leftFile >> (*solver)(i,j);

    for(int i=0;i<r;i++)
        rightFile >> (*solver)(i,c);

    try
    {
        vector<double> x = solver->solve();

        fout<<"Solution\n";
        for(int i=0;i<r;i++)
            fout<<"x"<<i+1<<" = "<<x[i]<<endl;
    }
    catch(const char* msg)
    {
        fout<<"Error: "<<msg<<endl;
    }

    delete solver;

    return 0;
}




// int main()
// {
//     ifstream leftFile("49/49l.txt");
//     ifstream rightFile("49/49r.txt");
//     ofstream fout("output.txt");

//     if(!leftFile || !rightFile)
//     {
//         fout<<"Error opening input files\n";
//         return 1;
//     }

//     int r,c;
//     leftFile >> r >> c;
//     Matrix A(r,c);
//     A.readFromFile(leftFile);

//     fout<<"Matrix A\n";
//     fout<<A<<endl;

//     fout<<"Transpose of A\n";
//     Matrix T = A.transpose();
//     fout<<T<<endl;

//     if(A.isSquare())
//     {
//         fout<<"Determinant = "<<A.determinant()<<endl;
//         try
//         {
//             Matrix inv = A.inverse();
//             fout<<"\nInverse Matrix\n";
//             fout<<inv;
//         }
//         catch(const char* msg)
//         {
//             fout<<msg<<endl;
//         }
//     }
//     else
//     {
//         fout<<"Matrix is not square\n";
//     }

//     fout<<"\nTranspose Matrix\n";
//     Matrix t = A.transpose();
//     fout<<t;

//     fout<<"\nMatrix Addition (A + A)\n";
//     fout<<A + A << endl;

//     fout<<"\nMatrix Subtraction (A - A)\n";
//     fout<<A - A << endl;

//     fout<<"\nMatrix Multiplication (A * A)\n";

//     if(A.isSquare())
//         fout<<A * A << endl;

//     fout<<"\nGaussian Elimination (Partial Pivot)\n";
//     leftFile.clear();
//     rightFile.clear();
//     leftFile.seekg(0);
//     rightFile.seekg(0);

//     leftFile >>r >>c;
//     //rightFile >>r;

//     partialPivot ge(r);

//     for(int i=0;i<r;i++)
//         for(int j=0;j<c;j++)
//             leftFile >> ge(i,j);

//     for(int i=0;i<r;i++)
//         rightFile >> ge(i,c);
//     try
//     {
//         ge.forwardElimination();
//         vector<double> x = ge.backSubstitution();
//         fout<<"Solution Vector\n";
//         for(int i=0;i<r;i++)
//             fout<<"x"<<i+1<<" = "<<x[i]<<endl;
//     }
//     catch(const char* msg)
//     {
//         fout<<msg<<endl;
//     }

//     fout<<"\nCrout Method\n";

//     leftFile.clear();
//     leftFile.seekg(0);
//     leftFile >> r >> c;

//     Crout cr(r);
//     cr.readFromFile(leftFile);
//     cr.decompose(fout);

//     fout<<"\nDoolittle Method\n";

//     leftFile.clear();
//     leftFile.seekg(0);
//     leftFile >> r >> c;

//     Doolittle dl(r);
//     dl.readFromFile(leftFile);
//     dl.decompose(fout);

//     fout<<"\nCholesky Method\n";

//     leftFile.clear();
//     leftFile.seekg(0);
//     leftFile >> r >> c;

//     Cholesky ch(r);
//     ch.readFromFile(leftFile);
//     try
//     {
//         ch.decompose(fout);
//     }
//     catch(const char* msg)
//     {
//         fout<<msg<<endl;
//     }

//     leftFile.close();
//     rightFile.close();
//     fout.close();

//     return 0;
// }
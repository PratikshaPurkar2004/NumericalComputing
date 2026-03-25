#include<cmath>
#include "root.hpp"

// Bisection::Bisection(double tol,double step)
// {
//     this->tol=tol;
//     this->step=step;
// }

// double Bisection::f(double x)
// {
//     return 4*x*x*x-3*x;
// }

// double Bisection:: df(double x)
// {
//     return 12*x*x-3;
// }

// double Bisection::g(double x)
// {
//     return cbrt((3*x)/4.0);   
// }

// double Bisection::bisection()
// {
//     double a=0,b=0;
//     for(double x=-2;x<2;x+=step)
//     {
//         if(f(x)*f(x+step)<0)
//         {
//             a=x;
//             b=x+step;
//             break;
//         }
//     }

//     double mid;

//     while(fabs(b-a)>tol)
//     {
//         mid=(a+b)/2;
//         if(f(a)*f(mid)<0)
//             b=mid;
//         else
//             a=mid;
//     }
//     return (a+b)/2;
// }

// int itr=100;
// double Bisection::newtonRaphson(double x0)
// {
//     double x1;
//     for(int i=0;i<itr;i++)
//     {
//         if(df(x0)==0)
//             return false;

//         x1=x0-f(x0)/df(x0);
        
//         if(fabs(x1-x0)<tol)
//             return x1;

//         x0=x1;
//     }
//     return x1;
// }

// double Bisection::fixedPoint(double x0)
// {
//     double x1;
//     int iter=100;

//     for(int i = 0; i <iter; i++)
//     {
//         x1 = g(x0);

//         if(fabs(x1 - x0) < tol)
//             return x1;

//         x0 = x1;
//     }
//     return false;
// }




Root::Root(double tol, double step)
{
    this->tol = tol;
    this->step = step;
}


double Root::f(double x)
{
    return 4*x*x*x - 3*x;
}

double Root::solve(double x0){}

Bisection::Bisection(double tol, double step): Root(tol, step) {}

double Bisection::solve(double x0)
{
    double a=0, b=0;

    for(double x=-2; x<2; x+=step)
    {
        if(f(x)*f(x+step)<0)
        {
            a=x;
            b=x+step;
            break;
        }
    }

    while(fabs(b-a)>tol)
    {
        double mid=(a+b)/2;

        if(f(a)*f(mid)<0)
            b=mid;
        else
            a=mid;
    }

    return (a+b)/2;
}


NewtonRaphson::NewtonRaphson(double tol): Root(tol) {}

double NewtonRaphson::solve(double x0)
{
    for(int i=0;i<100;i++)
    {
        double df = 12*x0*x0 - 3;

        if(df==0)
            return -1;

        double x1 = x0 - f(x0)/df;

        if(fabs(x1-x0)<tol)
            return x1;

        x0=x1;
    }

    return x0;
}


FixedPoint::FixedPoint(double tol): Root(tol) {}

double FixedPoint::solve(double x0)
{
    for(int i=0;i<100;i++)
    {
        double x1 = cbrt((3*x0)/4.0);

        if(fabs(x1-x0)<tol)
            return x1;

        x0=x1;
    }

    return -1;
}


// class Bisection{
//     private:
//         double tol;
//         double step;
//         double f(double x);
//         double df(double x);
//         double g(double x);

//     public:
//         Bisection(double tol=0.0001,double step=0.1);
//         double bisection();
//         double newtonRaphson(double x0);
//         double fixedPoint(double x0);
// };


#include <cmath>

class Root
{
protected:
    double tol;
    double step;

    double f(double x);

public:
    Root(double tol = 0.0001, double step = 0.1);
    virtual double solve(double x0 = 0) ;
};

class Bisection : public Root
{
public:
    Bisection(double tol = 0.0001, double step = 0.1);
    double solve(double x0 = 0);
};

class NewtonRaphson : public Root
{
public:
    NewtonRaphson(double tol = 0.0001);
    double solve(double x0);
};

class FixedPoint : public Root
{
public:
    FixedPoint(double tol = 0.0001);
    double solve(double x0);
};



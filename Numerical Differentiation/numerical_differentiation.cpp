#include "numerical_differentiation.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

NumericalDifferentiation::NumericalDifferentiation(std::function<double(double)> func,std::function<double(double)> derivative,double point)
{
    function = func;
    exactDerivative = derivative;
    x = point;
}


// Forward Difference
// f'(x) = [f(x+h) - f(x)] / h
double NumericalDifferentiation::forwardDifference(double h)
{
    return (function(x + h) - function(x)) / h;
}

// Backward Difference
// f'(x) = [f(x) - f(x-h)] / h
double NumericalDifferentiation::backwardDifference(double h)
{
    return (function(x) - function(x - h)) / h;
}

// Central Difference
// f'(x) = [f(x+h) - f(x-h)] / 2h
double NumericalDifferentiation::centralDifference(double h)
{
    return (function(x + h) - function(x - h)) / (2 * h);
}


double NumericalDifferentiation::absoluteError(double approximate)
{
    double exact = exactDerivative(x);
    return abs(exact - approximate);
}



void NumericalDifferentiation::printResults(const string& method,const vector<double>& hValues)
{
    cout << "\n==============================================\n";
    cout << "Method: " << method << endl;
    cout << "x = " << x << endl;
    cout << "==============================================\n";

    cout << left
         << setw(20) << "h"
         << setw(20) << "Approximate"
         << setw(20) << "Absolute Error"
         << endl;

    cout << "------------------------------------------------------------\n";


    for (double h : hValues)
    {
        double approximate;


        if (method == "Forward Difference")
        {
            approximate = forwardDifference(h);
        }
        else if (method == "Backward Difference")
        {
            approximate = backwardDifference(h);
        }
        else
        {
            approximate = centralDifference(h);
        }


        double error = absoluteError(approximate);


        cout << fixed << setprecision(10)
             << left
             << setw(20) << h
             << setw(20) << approximate
             << setw(20) << error
             << endl;
    }
}
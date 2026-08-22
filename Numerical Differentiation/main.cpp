#include <iostream>
#include <vector>
#include <cmath>
#include "numerical_differentiation.h"

using namespace std;

int main()
{
    auto function = [](double x)
    {
        return x * x * x + 2 * x * x - x + 1;
    };

    auto exactDerivative = [](double x)
    {
        return 3 * x * x + 4 * x - 1;
    };

    double x = 1.0;

    vector<double> hValues =
    {
        0.1,
        0.01,
        0.001,
        0.0001
    };

    NumericalDifferentiation n(function,exactDerivative, x );

    cout << "==============================================\n";
    cout << "       NUMERICAL DIFFERENTIATION\n";
    cout << "==============================================\n";

    cout << "Function: f(x) = x^3 + 2x^2 - x + 1\n";
    cout << "Derivative: f'(x) = 3x^2 + 4x - 1\n";
    cout << "x = " << x << endl;

    cout << "Exact derivative at x = 1: "
         << exactDerivative(x) << endl;

    n.printResults("Forward Difference",hValues);

    n.printResults("Backward Difference",hValues);

    n.printResults("Central Difference",hValues);
    return 0;
}
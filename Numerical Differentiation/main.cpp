#include <iostream>
#include <vector>
#include <cmath>
#include "numerical_differentiation.h"

using namespace std;

int main()
{
    // ------------------------------------------------
    // Function:
    // f(x) = x^3 + 2x^2 - x + 1
    // ------------------------------------------------

    auto function = [](double x)
    {
        return x * x * x + 2 * x * x - x + 1;
    };


    // ------------------------------------------------
    // Exact derivative:
    // f'(x) = 3x^2 + 4x - 1
    // ------------------------------------------------

    auto exactDerivative = [](double x)
    {
        return 3 * x * x + 4 * x - 1;
    };


    // Point at which derivative is calculated
    double x = 1.0;


    // Different h values
    vector<double> hValues =
    {
        0.1,
        0.01,
        0.001,
        0.0001
    };


    // Create object
    NumericalDifferentiation numericalDiff(
        function,
        exactDerivative,
        x
    );


    // Display problem information
    cout << "==============================================\n";
    cout << "       NUMERICAL DIFFERENTIATION\n";
    cout << "==============================================\n";

    cout << "Function: f(x) = x^3 + 2x^2 - x + 1\n";
    cout << "Derivative: f'(x) = 3x^2 + 4x - 1\n";
    cout << "x = " << x << endl;

    cout << "Exact derivative at x = 1: "
         << exactDerivative(x) << endl;


    // Forward Difference
    numericalDiff.printResults("Forward Difference",hValues);


    // Backward Difference
    numericalDiff.printResults("Backward Difference",hValues);


    // Central Difference
    numericalDiff.printResults("Central Difference",hValues);
    return 0;
}
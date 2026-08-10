#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <functional>

using namespace std;

const double X0 = 1.0;

struct TestFunction {
    string name;
    function<double(double)> f;
    function<double(double)> exactDerivative;
};

// Central difference:
// D(h) = [f(x+h) - f(x-h)] / (2h)
double centralDifference(const function<double(double)>& f, double x, double h)
{
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

// Richardson extrapolation for a second-order central difference:
// D(h) = f'(x) + C*h^2 + O(h^4)
// R(h) = [4D(h/2) - D(h)] / 3
double richardson(const function<double(double)>& f, double x, double h)
{
    double Dh = centralDifference(f, x, h);
    double Dh2 = centralDifference(f, x, h / 2.0);
    return (4.0 * Dh2 - Dh) / 3.0;
}

int main()
{
    vector<TestFunction> functions = {
        {
            "exp(x)",
            [](double x) { return exp(x); },
            [](double x) { return exp(x); }
        },
        {
            "sin(x)",
            [](double x) { return sin(x); },
            [](double x) { return cos(x); }
        },
        {
            "cos(x)",
            [](double x) { return cos(x); },
            [](double x) { return -sin(x); }
        },
        {
            "x^3 - 2x + 1",
            [](double x) { return x*x*x - 2.0*x + 1.0; },
            [](double x) { return 3.0*x*x - 2.0; }
        }
    };

    // Required h values: 10^-1, 10^-2, ..., 10^-8
    vector<double> hValues;
    for (int k = 1; k <= 8; ++k)
        hValues.push_back(pow(10.0, -k));

    cout << fixed << setprecision(12);

    ofstream csv("richardson_results.csv");
    csv << "Function,h,D(h),R(h),Exact,AbsErrorD,AbsErrorR\n";

    for (const auto& test : functions)
    {
        double exact = test.exactDerivative(X0);

        cout << "\n============================================================\n";
        cout << "Function: " << test.name << "   Evaluation point x = 1\n";
        cout << "Exact derivative = " << exact << "\n";
        cout << "============================================================\n";

        cout << left
             << setw(14) << "h"
             << setw(20) << "D(h)"
             << setw(20) << "R(h)"
             << setw(20) << "|Error D|"
             << setw(20) << "|Error R|" << "\n";

        for (double h : hValues)
        {
            double D = centralDifference(test.f, X0, h);
            double R = richardson(test.f, X0, h);
            double errorD = fabs(exact - D);
            double errorR = fabs(exact - R);

            cout << scientific << setprecision(8)
                 << setw(14) << h
                 << setw(20) << D
                 << setw(20) << R
                 << setw(20) << errorD
                 << setw(20) << errorR << "\n";

            csv << test.name << ","
                << setprecision(12) << h << ","
                << D << ","
                << R << ","
                << exact << ","
                << errorD << ","
                << errorR << "\n";
        }
    }

    csv.close();

    cout << "\nResults saved to richardson_results.csv\n";
    return 0;
}
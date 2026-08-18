
#include <functional>
#include <string>
#include <vector>

class NumericalDifferentiation
{
private:
    std::function<double(double)> function;
    std::function<double(double)> exactDerivative;
    double x;

public:
    // Constructor
    NumericalDifferentiation(
        std::function<double(double)> func,
        std::function<double(double)> derivative,
        double point
    );

    // Numerical differentiation methods
    double forwardDifference(double h);
    double backwardDifference(double h);
    double centralDifference(double h);

    // Error calculation
    double absoluteError(double approximate);

    // Display results
    void printResults(
        const std::string& method,
        const std::vector<double>& hValues
    );
};


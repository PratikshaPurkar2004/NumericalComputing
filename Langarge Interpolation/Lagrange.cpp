#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;


// ------------------------------------------------------------
// CSV parser
// Handles values with or without double quotes
// Example:
// "female","group B","bachelor's degree","standard","none","72"
// ------------------------------------------------------------
vector<string> parseCSVLine(const string& line)
{
    vector<string> fields;
    string field;
    bool insideQuotes = false;

    for (char c : line)
    {
        if (c == '"')
        {
            insideQuotes = !insideQuotes;
        }
        else if (c == ',' && !insideQuotes)
        {
            fields.push_back(field);
            field.clear();
        }
        else
        {
            field += c;
        }
    }

    fields.push_back(field);

    return fields;
}


// ------------------------------------------------------------
// Check whether string is numeric
// ------------------------------------------------------------
bool isNumber(const string& value)
{
    if (value.empty())
        return false;

    try
    {
        size_t position;
        stod(value, &position);

        return position == value.length();
    }
    catch (...)
    {
        return false;
    }
}


// ------------------------------------------------------------
// Lagrange Interpolation
// ------------------------------------------------------------
double lagrangeInterpolation(
    const vector<double>& x,
    const vector<double>& y,
    double targetX)
{
    int n = x.size();

    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                term *=
                    (targetX - x[j]) /
                    (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}


// ------------------------------------------------------------
// Find nearest points excluding target point
// ------------------------------------------------------------
vector<int> findNearestPoints(
    const vector<double>& x,
    int targetIndex,
    int numberOfPoints)
{
    vector<pair<double, int>> distances;

    for (int i = 0; i < x.size(); i++)
    {
        if (i == targetIndex)
            continue;

        double distance =
            abs(x[i] - x[targetIndex]);

        distances.push_back({ distance, i });
    }

    sort(
        distances.begin(),
        distances.end(),
        [](const pair<double, int>& a,
           const pair<double, int>& b)
        {
            return a.first < b.first;
        }
    );

    vector<int> selected;

    for (int i = 0;
         i < numberOfPoints &&
         i < distances.size();
         i++)
    {
        selected.push_back(distances[i].second);
    }

    return selected;
}


// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main()
{
    cout << "============================================\n";
    cout << "       GENERIC LAGRANGE INTERPOLATION\n";
    cout << "============================================\n";


    // --------------------------------------------------------
    // 1. Ask CSV filename
    // --------------------------------------------------------

    string filename;

    cout << "\nEnter CSV filename: ";
    cin >> filename;


    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "\nError: Could not open file.\n";
        return 1;
    }


    // --------------------------------------------------------
    // 2. Read header
    // --------------------------------------------------------

    string line;

    getline(file, line);

    vector<string> headers =
        parseCSVLine(line);


    cout << "\nAvailable columns:\n";

    cout << "--------------------------------------------\n";

    for (int i = 0; i < headers.size(); i++)
    {
        cout << i
             << " : "
             << headers[i]
             << endl;
    }


    // --------------------------------------------------------
    // 3. Ask X and Y columns
    // --------------------------------------------------------

    int xColumn;
    int yColumn;

    cout << "\nEnter X column number: ";
    cin >> xColumn;

    cout << "Enter Y column number: ";
    cin >> yColumn;


    if (xColumn < 0 ||
        xColumn >= headers.size() ||
        yColumn < 0 ||
        yColumn >= headers.size())
    {
        cout << "\nError: Invalid column number.\n";
        return 1;
    }


    // --------------------------------------------------------
    // 4. Read dataset
    // --------------------------------------------------------

    vector<double> x;
    vector<double> y;

    int rowNumber = 1;

    while (getline(file, line))
    {
        if (line.empty())
            continue;


        vector<string> fields =
            parseCSVLine(line);


        if (xColumn >= fields.size() ||
            yColumn >= fields.size())
        {
            continue;
        }


        string xValue = fields[xColumn];
        string yValue = fields[yColumn];


        // Skip missing/non-numeric values
        if (!isNumber(xValue) ||
            !isNumber(yValue))
        {
            continue;
        }


        double xNumber = stod(xValue);
        double yNumber = stod(yValue);


        x.push_back(xNumber);
        y.push_back(yNumber);

        rowNumber++;
    }

    file.close();


    // --------------------------------------------------------
    // 5. Display dataset information
    // --------------------------------------------------------

    cout << "\n============================================\n";
    cout << "             DATASET INFORMATION\n";
    cout << "============================================\n";

    cout << "Dataset file       : "
         << filename << endl;

    cout << "X variable         : "
         << headers[xColumn] << endl;

    cout << "Y variable         : "
         << headers[yColumn] << endl;

    cout << "Total observations : "
         << x.size() << endl;


    if (x.size() < 3)
    {
        cout << "\nNot enough numeric observations.\n";
        return 1;
    }


    // --------------------------------------------------------
    // 6. Check duplicate X values
    // --------------------------------------------------------

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = i + 1; j < x.size(); j++)
        {
            if (x[i] == x[j])
            {
                cout << "\nWarning:\n";
                cout << "Duplicate X values found.\n";
                cout << "Lagrange interpolation requires\n";
                cout << "distinct X values.\n";

                return 1;
            }
        }
    }


    // --------------------------------------------------------
    // 7. Ask polynomial degree
    // --------------------------------------------------------

    int degree;

    cout << "\nEnter polynomial degree: ";
    cin >> degree;


    if (degree < 1)
    {
        cout << "\nDegree must be at least 1.\n";
        return 1;
    }


    int requiredPoints = degree + 1;


    if (requiredPoints >= x.size())
    {
        cout << "\nNot enough observations for this degree.\n";

        cout << "Required points : "
             << requiredPoints << endl;

        cout << "Available points: "
             << x.size() << endl;

        return 1;
    }


    // --------------------------------------------------------
    // 8. Select target observation
    // --------------------------------------------------------

    int targetIndex;

    cout << "\nEnter target observation number (1 - "
         << x.size()
         << "): ";

    cin >> targetIndex;


    targetIndex--;


    if (targetIndex < 0 ||
        targetIndex >= x.size())
    {
        cout << "\nInvalid observation number.\n";
        return 1;
    }


    // --------------------------------------------------------
    // 9. Actual value
    // --------------------------------------------------------

    double targetX =
        x[targetIndex];

    double actualY =
        y[targetIndex];

    vector<int> selectedIndices =
        findNearestPoints(
            x,
            targetIndex,
            requiredPoints
        );


    vector<double> interpolationX;
    vector<double> interpolationY;


    for (int index : selectedIndices)
    {
        interpolationX.push_back(x[index]);
        interpolationY.push_back(y[index]);
    }


    double approximateY =lagrangeInterpolation( interpolationX, interpolationY,targetX);


    double absoluteError =
        abs(actualY - approximateY);


    double percentageError = 0.0;


    if (actualY != 0)
    {
        percentageError =
            (absoluteError / abs(actualY)) * 100;
    }

    cout << "\n============================================\n";
    cout << "        INTERPOLATION POINTS\n";
    cout << "============================================\n";

    cout << left
         << setw(15) << "X"
         << setw(15) << "Y"
         << endl;

    cout << "--------------------------------------------\n";

    for (int i = 0;
         i < interpolationX.size();
         i++)
    {
        cout << left
             << setw(15)
             << interpolationX[i]

             << setw(15)
             << interpolationY[i]

             << endl;
    }

    cout << fixed
         << setprecision(6);


    cout << "\n============================================\n";
    cout << "        LAGRANGE INTERPOLATION RESULT\n";
    cout << "============================================\n";

    cout << "Polynomial degree : "
         << degree
         << endl;

    cout << "Points used       : "
         << requiredPoints
         << endl;

    cout << "Target X          : "
         << targetX
         << endl;

    cout << "Actual Y          : "
         << actualY
         << endl;

    cout << "Approximate Y     : "
         << approximateY
         << endl;

    cout << "Absolute Error    : "
         << absoluteError
         << endl;

    cout << "Percentage Error  : "
         << percentageError
         << " %"
         << endl;

    cout << "============================================\n";


    return 0;
}
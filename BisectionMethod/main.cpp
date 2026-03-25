#include <iostream>
#include "root.hpp"

using namespace std;

int main()
{
    Root r;
    cout<<"root are::"<<r.solve()<<endl;

    Bisection b;
    cout << "Bisection root: " << b.solve() << endl;

    NewtonRaphson n;
    cout << "Newton root: " << n.solve(1.0) << endl;

    FixedPoint f;
    cout << "Fixed Point root: " << f.solve(1.0) << endl;

    return 0;
}

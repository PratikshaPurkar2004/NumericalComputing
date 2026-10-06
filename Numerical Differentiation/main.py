from cmath import cos, sin

from ForwordDifference import ForwardDifference
from BackwordDifference import BackwardDifference
from CentralDifference import CentralDifference
from RichardsonExtrapolation import RichardsonExtrapolation
from LagrangeInterpolation import LagrangeInterpolation
from NewtonDividedDifference import NewtonDividedDifference

from TrapezoidalRule import Trapezoidal
from simpsonOneThird import SimpsonOneThird
from simpsonThreeEight import SimpsonThreeEight

from Graph import Graph


# =================================================
# Function
# =================================================

def function(x):

    return x**2


# =================================================
# Exact derivative
# =================================================

def exact_derivative(x):

    return 2*x


# =================================================
# Step sizes for numerical differentiation
# =================================================

h_values = [
    0.1,
    0.01,
    0.001,
    0.0001
]


# =================================================
# Menu
# =================================================

print("\n==============================================")
print("             NUMERICAL METHODS")
print("==============================================")

print("1. Forward Difference")
print("2. Backward Difference")
print("3. Central Difference")
print("4. Richardson Extrapolation")
print("5. Lagrange Interpolation")
print("6. Newton Divided Difference")
print("7. Numerical Integration")

print("==============================================")


choice = int(
    input("Enter your choice: ")
)


# =================================================
# Forward Difference
# =================================================

if choice == 1:

    # ---------------------------------------------
    # Take x only for numerical differentiation
    # ---------------------------------------------

    x = float(
        input("Enter value of x: ")
    )


    # ---------------------------------------------
    # Create objects
    # ---------------------------------------------

    forward = ForwardDifference(
        function,
        exact_derivative,
        x
    )

    backward = BackwardDifference(
        function,
        exact_derivative,
        x
    )

    central = CentralDifference(
        function,
        exact_derivative,
        x
    )

    richardson = RichardsonExtrapolation(
        function,
        exact_derivative,
        x
    )


    # ---------------------------------------------
    # Exact derivative
    # ---------------------------------------------

    exact = exact_derivative(x)


    print("\n==============================================")
    print("           FORWARD DIFFERENCE")
    print("==============================================")

    print(
        "Exact Derivative :",
        exact
    )

    print(
        "x value          :",
        x
    )


    print(
        "\n{:<12} {:<25} {:<20}".format(
            "h",
            "Approximate Derivative",
            "Absolute Error"
        )
    )

    print("-" * 57)


    for h in h_values:

        result = forward.calculate(h)

        error = forward.absolute_error(
            result
        )


        print(
            "{:<12.4f} {:<25.10f} {:<20.10f}".format(
                h,
                result,
                error
            )
        )


    # ---------------------------------------------
    # Graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        None
    )


    graph.plot_error(
        h_values,
        exact_derivative,
        x
    )


# =================================================
# Backward Difference
# =================================================

elif choice == 2:

    # ---------------------------------------------
    # Take x only for numerical differentiation
    # ---------------------------------------------

    x = float(
        input("Enter value of x: ")
    )


    # ---------------------------------------------
    # Create objects
    # ---------------------------------------------

    forward = ForwardDifference(
        function,
        exact_derivative,
        x
    )

    backward = BackwardDifference(
        function,
        exact_derivative,
        x
    )

    central = CentralDifference(
        function,
        exact_derivative,
        x
    )

    richardson = RichardsonExtrapolation(
        function,
        exact_derivative,
        x
    )


    # ---------------------------------------------
    # Exact derivative
    # ---------------------------------------------

    exact = exact_derivative(x)


    print("\n==============================================")
    print("           BACKWARD DIFFERENCE")
    print("==============================================")

    print(
        "Exact Derivative :",
        exact
    )

    print(
        "x value          :",
        x
    )


    print(
        "\n{:<12} {:<25} {:<20}".format(
            "h",
            "Approximate Derivative",
            "Absolute Error"
        )
    )

    print("-" * 57)


    for h in h_values:

        result = backward.calculate(h)

        error = backward.absolute_error(
            result
        )


        print(
            "{:<12.4f} {:<25.10f} {:<20.10f}".format(
                h,
                result,
                error
            )
        )


    # ---------------------------------------------
    # Graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        None
    )


    graph.plot_error(
        h_values,
        exact_derivative,
        x
    )


# =================================================
# Central Difference
# =================================================

elif choice == 3:

    # ---------------------------------------------
    # Take x only for numerical differentiation
    # ---------------------------------------------

    x = float(
        input("Enter value of x: ")
    )


    # ---------------------------------------------
    # Create objects
    # ---------------------------------------------

    forward = ForwardDifference(
        function,
        exact_derivative,
        x
    )

    backward = BackwardDifference(
        function,
        exact_derivative,
        x
    )

    central = CentralDifference(
        function,
        exact_derivative,
        x
    )

    richardson = RichardsonExtrapolation(
        function,
        exact_derivative,
        x
    )


    # ---------------------------------------------
    # Exact derivative
    # ---------------------------------------------

    exact = exact_derivative(x)


    print("\n==============================================")
    print("           CENTRAL DIFFERENCE")
    print("==============================================")

    print(
        "Exact Derivative :",
        exact
    )

    print(
        "x value          :",
        x
    )


    print(
        "\n{:<12} {:<25} {:<20}".format(
            "h",
            "Approximate Derivative",
            "Absolute Error"
        )
    )

    print("-" * 57)


    for h in h_values:

        result = central.calculate(h)

        error = central.absolute_error(
            result
        )


        print(
            "{:<12.4f} {:<25.10f} {:<20.10f}".format(
                h,
                result,
                error
            )
        )


    # ---------------------------------------------
    # Graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        None
    )


    graph.plot_error(
        h_values,
        exact_derivative,
        x
    )


# =================================================
# Richardson Extrapolation
# =================================================

elif choice == 4:

    # ---------------------------------------------
    # Take x only for numerical differentiation
    # ---------------------------------------------

    x = float(
        input("Enter value of x: ")
    )


    # ---------------------------------------------
    # Create objects
    # ---------------------------------------------

    forward = ForwardDifference(
        function,
        exact_derivative,
        x
    )

    backward = BackwardDifference(
        function,
        exact_derivative,
        x
    )

    central = CentralDifference(
        function,
        exact_derivative,
        x
    )

    richardson = RichardsonExtrapolation(
        function,
        exact_derivative,
        x
    )

    exact = exact_derivative(x)


    print("\n==============================================")
    print("        RICHARDSON EXTRAPOLATION")
    print("==============================================")

    print(
        "Exact Derivative :",
        exact
    )

    print(
        "x value          :",
        x
    )


    print(
        "\n{:<12} {:<25} {:<20}".format(
            "h",
            "Approximate Derivative",
            "Absolute Error"
        )
    )

    print("-" * 57)


    for h in h_values:

        result = richardson.calculate(h)

        error = richardson.absolute_error( result)


        print(
            "{:<12.4f} {:<25.10f} {:<20.10f}".format(
                h,
                result,
                error
            )
        )

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        None
    )


    graph.plot_error(
        h_values,
        exact_derivative,
        x
    )


elif choice == 5:

    print("\n==============================================")
    print("           LAGRANGE INTERPOLATION")
    print("==============================================")


    n = int( input("Enter number of data points: "))

    x_values = []

    print("\nEnter known x values:")

    for i in range(n):

        value = float( input(f"x[{i}] = "))

        x_values.append(value)

    y_values = []

    print("\nEnter corresponding y values:")

    for i in range(n):

        value = float(input(f"y[{i}] = "))

        y_values.append(value)


    interpolation_x = float(input("\nEnter x value to interpolate: "))

    lagrange = LagrangeInterpolation( function )


    polynomial = lagrange.calculate(
        x_values,
        y_values
    )


    print("\n==============================================")
    print("           LAGRANGE POLYNOMIAL")
    print("==============================================")

    print( "P(x) =",polynomial)

    result = lagrange.evaluate( polynomial, interpolation_x)

    exact_value = function( interpolation_x)

    error = lagrange.absolute_error( interpolation_x, result )

    print("\n==============================================")
    print("                 RESULT")
    print("==============================================")


    print( "x value :", interpolation_x)

    print("Interpolated Value:",result)

    print("Exact Value       :",exact_value)

    print( "Absolute Error    :",error)

    graph = Graph(
        None,
        None,
        None,
        None,
        lagrange,
        None
    )


    graph.plot_lagrange(
        function,
        x_values,
        y_values
    )

elif choice == 6:

    print("\n==============================================")
    print("        NEWTON DIVIDED DIFFERENCE")
    print("==============================================")

    n = int(input("Enter number of data points: "))

    x_values = []

    print("\nEnter known x values:")

    for i in range(n):

        value = float( input(f"x[{i}] = "))

        x_values.append(value)

    y_values = []

    print("\nEnter corresponding y values:")

    for i in range(n):

        value = float( input(f"y[{i}] = ") )

        y_values.append(value)


    interpolation_x = float( input("\nEnter x value to interpolate: "))


    newton = NewtonDividedDifference( function)

    table = newton.divided_difference_table( x_values, y_values)


    print("\n==============================================")
    print("       DIVIDED DIFFERENCE TABLE")
    print("==============================================")


    print(
        "{:<12}".format("x"),
        end=""
    )


    for i in range(n):

        print(
            "{:<15}".format(
                f"DD-{i}"
            ),
            end=""
        )


    print()

    print( "-" * (12 + 15 * n) )


    for i in range(n):

        print(
            "{:<12.4f}".format(
                x_values[i]
            ),
            end=""
        )


        for j in range(n - i):

            print(
                "{:<15.6f}".format(
                    table[i][j]
                ),
                end=""
            )


        print()

    polynomial = newton.calculate(x_values,y_values)


    print("\n==============================================")
    print("           NEWTON POLYNOMIAL")
    print("==============================================")


    print( "P(x) =", polynomial )

    result = newton.evaluate(
        x_values,
        y_values,
        interpolation_x
    )

    exact_value = function( interpolation_x)

    error = newton.absolute_error(
        x_values,
        y_values,
        interpolation_x
    )

    print("\n==============================================")
    print("                 RESULT")
    print("==============================================")


    print(
        "x value           :",
        interpolation_x
    )

    print(
        "Interpolated Value:",
        result
    )

    print(
        "Exact Value       :",
        exact_value
    )

    print(
        "Absolute Error    :",
        error
    )

    graph = Graph(
        None,
        None,
        None,
        None,
        None,
        newton
    )


    graph.plot_newton(
        function,
        x_values,
        y_values
    )


elif choice == 7:

    print("\n==============================================")
    print("             NUMERICAL INTEGRATION")
    print("==============================================")

    def integration_function(x):
        return sin(x)

    def exact_integral_function(x):
         return -cos(x)

    lower = float( input("Enter lower limit: "))
    upper = float( input("Enter upper limit: ") )

    number_of_n = int(input("Enter number of n values: "))
    n_values = []

    print("\nEnter n values:")
    for i in range(number_of_n):
        n = int(input(f"Enter n value {i + 1}: "))

        n_values.append(n)

    trapezoidal = Trapezoidal( integration_function,lower,upper)
    simpson13 = SimpsonOneThird(integration_function,lower,upper)
    simpson38 = SimpsonThreeEight( integration_function,lower,upper)

    exact = (exact_integral_function(upper) - exact_integral_function(lower))

    print("\n==============================================")
    print("             INTEGRATION INFO")
    print("==============================================")


    print( "Function       : x^2")

    print( "Lower Limit    :",lower)
    print("Upper Limit    :",upper)
    print("Exact Integral :", exact)

    trapezoidal_errors = []

    simpson13_errors = []

    simpson38_errors = []

    print("\n")
    print("==============================================================")
    print("                    TRAPEZOIDAL RULE")
    print("==============================================================")


    print(
        "{:<10} {:<15} {:<25} {:<20}".format(
            "n",
            "h",
            "Numerical Integration",
            "Absolute Error"
        )
    )

    print("-" * 70)


    for n in n_values:

        h = ( (upper - lower) / n)

        result = trapezoidal.trapezoidal(n)

        error = abs( exact - result)
        trapezoidal_errors.append(error)

        print(
            "{:<10} {:<15.6f} {:<25.10f} {:<20.10f}".format(
                n,
                h,
                result,
                error
            )
        )

    print("\n")
    print("==============================================================")
    print("                   SIMPSON 1/3 RULE")
    print("==============================================================")


    print(
        "{:<10} {:<15} {:<25} {:<20}".format(
            "n",
            "h",
            "Numerical Integration",
            "Absolute Error"
        )
    )

    print("-" * 70)


    for n in n_values:

        h = ((upper - lower) / n)
        try:

            result = simpson13.simpsonOneThird( n )

            error = abs( exact - result)
            simpson13_errors.append(error)

            print(
                "{:<10} {:<15.6f} {:<25.10f} {:<20.10f}".format(
                    n,
                    h,
                    result,
                    error
                )
            )


        except ValueError:
            simpson13_errors.append( None )
            print(
                "{:<10} {:<15.6f} {:<25} {:<20}".format(
                    n,
                    h,
                    "-",
                    "-"
                )
            )

    print("\n")
    print("==============================================================")
    print("                   SIMPSON 3/8 RULE")
    print("==============================================================")


    print(
        "{:<10} {:<15} {:<25} {:<20}".format(
            "n",
            "h",
            "Numerical Integration",
            "Absolute Error"
        )
    )

    print("-" * 70)


    for n in n_values:
        h = ( (upper - lower) / n)
        try:

            result = simpson38.simpsonThreeEight(n)
            error = abs( exact - result)

            simpson38_errors.append( error)

            print(
                "{:<10} {:<15.6f} {:<25.10f} {:<20.10f}".format(
                    n,
                    h,
                    result,
                    error
                )
            )


        except ValueError:
            simpson38_errors.append( None )
            print(
                "{:<10} {:<15.6f} {:<25} {:<20}".format(
                    n,
                    h,
                    "-",
                    "-"
                )
            )
    graph = Graph(
        None,
        None,
        None,
        None,
        None,
        None
    )


    graph.plot_integration_error(
        n_values,
        trapezoidal_errors,
        simpson13_errors,
        simpson38_errors
    )

else:

    print("\nInvalid choice!")
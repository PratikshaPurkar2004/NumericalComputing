from ForwordDifference import ForwardDifference
from BackwordDifference import BackwardDifference
from CentralDifference import CentralDifference
from RichardsonExtrapolation import RichardsonExtrapolation
from LagrangeInterpolation import LagrangeInterpolation
from NewtonDividedDifference import NewtonDividedDifference
from Graph import Graph


# ------------------------------------------------
# Function
# ------------------------------------------------

def function(x):
    return x**3 + 2*x**2 - x + 1


# ------------------------------------------------
# Exact derivative
# ------------------------------------------------

def exact_derivative(x):
    return 3*x**2 + 4*x - 1


# ------------------------------------------------
# Take x value only ONCE
# ------------------------------------------------

x = float(input("Enter value of x: "))


# ------------------------------------------------
# Step sizes
# ------------------------------------------------

h_values = [0.1, 0.01, 0.001, 0.0001]


# ------------------------------------------------
# Create objects
# ------------------------------------------------

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

newton = NewtonDividedDifference(
    function
)


# ------------------------------------------------
# Menu
# ------------------------------------------------

print("\n==============================================")
print("             NUMERICAL METHODS")
print("==============================================")
print("1. Forward Difference")
print("2. Backward Difference")
print("3. Central Difference")
print("4. Richardson Extrapolation")
print("5. Lagrange Interpolation")
print("6. Newton Divided Difference")
print("==============================================")


choice = int(input("Enter your choice: "))


# =================================================
# Forward Difference
# =================================================

if choice == 1:

    exact = exact_derivative(x)

    print("\n==============================================")
    print("           FORWARD DIFFERENCE")
    print("==============================================")

    print("Method           :", "Forward Difference")
    print("Exact Derivative :", exact)
    print("x value          :", x)

    print("\n{:<12} {:<25} {:<20}".format(
        "h",
        "Approximate Derivative",
        "Absolute Error"
    ))

    print("-" * 57)

    for h in h_values:

        result = forward.calculate(h)

        error = forward.absolute_error(result)

        print("{:<12.4f} {:<25.10f} {:<20.10f}".format(
            h,
            result,
            error
        ))

    # ---------------------------------------------
    # Show graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        newton
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

    exact = exact_derivative(x)

    print("\n==============================================")
    print("           BACKWARD DIFFERENCE")
    print("==============================================")

    print("Method           :", "Backward Difference")
    print("Exact Derivative :", exact)
    print("x value          :", x)

    print("\n{:<12} {:<25} {:<20}".format(
        "h",
        "Approximate Derivative",
        "Absolute Error"
    ))

    print("-" * 57)

    for h in h_values:

        result = backward.calculate(h)

        error = backward.absolute_error(result)

        print("{:<12.4f} {:<25.10f} {:<20.10f}".format(
            h,
            result,
            error
        ))

    # ---------------------------------------------
    # Show graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        newton
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

    exact = exact_derivative(x)

    print("\n==============================================")
    print("           CENTRAL DIFFERENCE")
    print("==============================================")

    print("Method           :", "Central Difference")
    print("Exact Derivative :", exact)
    print("x value          :", x)

    print("\n{:<12} {:<25} {:<20}".format(
        "h",
        "Approximate Derivative",
        "Absolute Error"
    ))

    print("-" * 57)

    for h in h_values:

        result = central.calculate(h)

        error = central.absolute_error(result)

        print("{:<12.4f} {:<25.10f} {:<20.10f}".format(
            h,
            result,
            error
        ))

    # ---------------------------------------------
    # Show graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        newton
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

    exact = exact_derivative(x)

    print("\n==============================================")
    print("        RICHARDSON EXTRAPOLATION")
    print("==============================================")

    print("Method           :", "Richardson Extrapolation")
    print("Exact Derivative :", exact)
    print("x value          :", x)

    print("\n{:<12} {:<25} {:<20}".format(
        "h",
        "Approximate Derivative",
        "Absolute Error"
    ))

    print("-" * 57)

    for h in h_values:

        result = richardson.calculate(h)

        error = richardson.absolute_error(result)

        print("{:<12.4f} {:<25.10f} {:<20.10f}".format(
            h,
            result,
            error
        ))

    # ---------------------------------------------
    # Show graph
    # ---------------------------------------------

    graph = Graph(
        forward,
        backward,
        central,
        richardson,
        None,
        newton
    )

    graph.plot_error(
        h_values,
        exact_derivative,
        x
    )


# =================================================
# Lagrange Interpolation
# =================================================

elif choice == 5:

    print("\n==============================================")
    print("           LAGRANGE INTERPOLATION")
    print("==============================================")

    # ---------------------------------------------
    # Number of known data points
    # ---------------------------------------------

    n = int(
        input("Enter number of data points: ")
    )

    # ---------------------------------------------
    # Known x values
    # ---------------------------------------------

    x_values = []

    print("\nEnter known x values:")

    for i in range(n):

        value = float(
            input(f"x[{i}] = ")
        )

        x_values.append(value)

    # ---------------------------------------------
    # Known y values
    # ---------------------------------------------

    y_values = []

    print("\nEnter corresponding y values:")

    for i in range(n):

        value = float(
            input(f"y[{i}] = ")
        )

        y_values.append(value)

    # ---------------------------------------------
    # Create Lagrange object
    # ---------------------------------------------

    lagrange = LagrangeInterpolation(
        function
    )

    # ---------------------------------------------
    # Create Lagrange polynomial
    # ---------------------------------------------

    polynomial = lagrange.calculate(
        x_values,
        y_values
    )

    print("\n==============================================")
    print("           LAGRANGE POLYNOMIAL")
    print("==============================================")

    print("P(x) =", polynomial)

    # ---------------------------------------------
    # Evaluate at SAME x entered at beginning
    # ---------------------------------------------

    result = lagrange.evaluate(
        polynomial,
        x
    )

    # ---------------------------------------------
    # Absolute error
    # ---------------------------------------------

    error = lagrange.absolute_error(
        x,
        result
    )

    print("\n==============================================")
    print("                 RESULT")
    print("==============================================")

    print("Polynomial        :", polynomial)
    print("x value           :", x)
    print("Interpolated Value :", result)
    print("Exact Value       :", function(x))
    print("Absolute Error    :", error)

    # ---------------------------------------------
    # Show Lagrange graph
    # ---------------------------------------------

    graph = Graph(
        None,
        None,
        None,
        None,
        lagrange,
        newton
    )

    graph.plot_lagrange(
        function,
        x_values,
        y_values
    )


# =================================================
# Newton Divided Difference
# =================================================

elif choice == 6:

    print("\n==============================================")
    print("        NEWTON DIVIDED DIFFERENCE")
    print("==============================================")

    # ---------------------------------------------
    # Number of known data points
    # ---------------------------------------------

    n = int(
        input("Enter number of data points: ")
    )

    # ---------------------------------------------
    # Known x values
    # ---------------------------------------------

    x_values = []

    print("\nEnter known x values:")

    for i in range(n):

        value = float(
            input(f"x[{i}] = ")
        )

        x_values.append(value)

    # ---------------------------------------------
    # Known y values
    # ---------------------------------------------

    y_values = []

    print("\nEnter corresponding y values:")

    for i in range(n):

        value = float(
            input(f"y[{i}] = ")
        )

        y_values.append(value)

    # ---------------------------------------------
    # Calculate divided difference table
    # ---------------------------------------------

    table = newton.divided_difference_table(
        x_values,
        y_values
    )

    # ---------------------------------------------
    # Display divided difference table
    # ---------------------------------------------

    print("\n==============================================")
    print("       DIVIDED DIFFERENCE TABLE")
    print("==============================================")

    # Dynamic header
    print("{:<12}".format("x"), end="")

    for i in range(n):
        print(
            "{:<15}".format(
                f"DD-{i}"
            ),
            end=""
        )

    print()

    print("-" * (12 + 15 * n))

    # Table values
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

    # ---------------------------------------------
    # Create Newton polynomial
    # ---------------------------------------------

    polynomial = newton.calculate(
        x_values,
        y_values
    )

    print("\n==============================================")
    print("           NEWTON POLYNOMIAL")
    print("==============================================")

    print("P(x) =", polynomial)

    # ---------------------------------------------
    # Evaluate at SAME x entered at beginning
    # ---------------------------------------------

    result = newton.evaluate(
        x_values,
        y_values,
        x
    )

    # ---------------------------------------------
    # Exact value
    # ---------------------------------------------

    exact_value = function(x)

    # ---------------------------------------------
    # Absolute error
    # ---------------------------------------------

    error = newton.absolute_error(
        x_values,
        y_values,
        x
    )

    # ---------------------------------------------
    # Result
    # ---------------------------------------------

    print("\n==============================================")
    print("                 RESULT")
    print("==============================================")

    print(
        "Method            :",
        "Newton Divided Difference"
    )

    print(
        "x value           :",
        x
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

    # ---------------------------------------------
    # Show Newton graph
    # ---------------------------------------------

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


# =================================================
# Invalid choice
# =================================================

else:

    print("\nInvalid choice!")
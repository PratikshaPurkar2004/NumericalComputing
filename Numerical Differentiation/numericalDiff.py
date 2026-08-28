class NumericalDifferentiation:

    def __init__(self, function, exact_derivative, x):
        self.function = function
        self.exact_derivative = exact_derivative
        self.x = x

    # Forward Difference
    def forward_difference(self, h):
        return (self.function(self.x + h) -
                self.function(self.x)) / h

    # Backward Difference
    def backward_difference(self, h):
        return (self.function(self.x) -
                self.function(self.x - h)) / h

    # Central Difference
    def central_difference(self, h):
        return (self.function(self.x + h) -
                self.function(self.x - h)) / (2 * h)

    # Absolute Error
    def absolute_error(self, approximate):
        exact = self.exact_derivative(self.x)
        return abs(exact - approximate)

    # Print Results
    def print_results(self, method, h_values):

        print("\n==============================================")
        print("Method:", method)
        print("x =", self.x)
        print("==============================================")

        print(f"{'h':<15}{'Approximate':<20}{'Absolute Error':<20}")
        print("-" * 55)

        for h in h_values:

            if method == "Forward Difference":
                approximate = self.forward_difference(h)

            elif method == "Backward Difference":
                approximate = self.backward_difference(h)

            else:
                approximate = self.central_difference(h)

            error = self.absolute_error(approximate)

            print(f"{h:<15.4f}{approximate:<20.10f}{error:<20.10f}")


# ------------------------------------------------
# Main Program
# ------------------------------------------------

# Function
def function(x):
    return x**3 + 2*x**2 - x + 1


# Exact derivative
def exact_derivative(x):
    return 3*x**2 + 4*x - 1


# Take x value from user
x = float(input("Enter the value of x: "))


# h values
h_values = [0.1, 0.01, 0.001, 0.0001]


# Create object
n = NumericalDifferentiation(
    function,
    exact_derivative,
    x
)


# Display information
print("       NUMERICAL DIFFERENTIATION")
print("__________________________________________________")

print("Function: f(x) = x^3 + 2x^2 - x + 1")
print("Derivative: f'(x) = 3x^2 + 4x - 1")
print("x =", x)

print("Exact derivative:",exact_derivative(x))


# Results
n.print_results("Forward Difference", h_values)

n.print_results("Backward Difference", h_values)

n.print_results("Central Difference", h_values)


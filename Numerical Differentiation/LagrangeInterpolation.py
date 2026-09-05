import sympy as sp


class LagrangeInterpolation:

    def __init__(self, function):
        self.function = function

    def calculate(self, x_values, y_values):

        x = sp.Symbol("x")

        n = len(x_values)

        polynomial = 0

        for i in range(n):
            L = 1
            for j in range(n):
                if i != j:
                    L = L * ((x - x_values[j])/ (x_values[i] - x_values[j]))

            polynomial = polynomial + y_values[i] * L

        return sp.expand(polynomial)

    # Put x value into polynomial
    def evaluate(self, polynomial, x_value):
        x = sp.Symbol("x")
        return float(polynomial.subs(x, x_value))

    # Calculate absolute error
    def absolute_error(self, x_value, approximate):
        exact = self.function(x_value)
        return abs(exact - approximate)
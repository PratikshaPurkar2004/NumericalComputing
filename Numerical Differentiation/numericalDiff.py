class NumericalDifferentiation:

    def __init__(self, function, exact_derivative, x):
        self.function = function
        self.exact_derivative = exact_derivative
        self.x = x

    def absolute_error(self, approximate):
        exact = self.exact_derivative(self.x)

        return abs(exact - approximate)
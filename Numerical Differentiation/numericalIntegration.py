class NumericalIntegration:

    def __init__(self, function, lower, upper):
        self.function = function
        self.lower = lower
        self.upper = upper

    def calculate_h(self, n):
        return (self.upper - self.lower) / n

    def exact_integral(self, exact_function):
        return exact_function(
            self.upper
        ) - exact_function(
            self.lower
        )

    def absolute_error(self, numerical_result, exact_result):
        return abs(exact_result - numerical_result)
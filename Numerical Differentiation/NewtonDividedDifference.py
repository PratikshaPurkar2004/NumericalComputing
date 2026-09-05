class NewtonDividedDifference:

    def __init__(self, function):
        self.function = function

    def divided_difference_table(self, x_values, y_values):

        n = len(x_values)

        table = []

        for i in range(n):
            row = [0.0] * n
            table.append(row)

        # First column = y values
        for i in range(n):
            table[i][0] = y_values[i]

        # Calculate divided differences
        for j in range(1, n):
            for i in range(n - j):
                table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x_values[i + j] - x_values[i])
        return table

    def calculate(self, x_values, y_values):

        table = self.divided_difference_table(x_values,y_values)

        n = len(x_values)

        # Newton polynomial as string
        polynomial = ""
        for i in range(n):
            coefficient = table[0][i]

            if i == 0:
                polynomial += f"{coefficient:.6f}"

            else:
                polynomial += f" + ({coefficient:.6f})"

                for j in range(i):
                    polynomial += f"(x - {x_values[j]})"
        return polynomial


    def evaluate(self, x_values, y_values, x):

        table = self.divided_difference_table(x_values,y_values )
        n = len(x_values)
        result = table[0][0]
        product = 1.0

        for i in range(1, n):
            product = product * (x - x_values[i - 1])
            result = result + table[0][i] * product
        return result


    def absolute_error(self, x_values, y_values, x):
        result = self.evaluate( x_values,y_values,x)
        exact = self.function(x)
        return abs(exact - result)
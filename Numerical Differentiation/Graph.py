import matplotlib.pyplot as plt


class Graph:

    def __init__(
        self,
        forward,
        backward,
        central,
        richardson,
        lagrange,
        newton
    ):

        self.forward = forward
        self.backward = backward
        self.central = central
        self.richardson = richardson
        self.lagrange = lagrange
        self.newton = newton


    # -----------------------------------------
    # Numerical Differentiation Graph
    # -----------------------------------------

    def plot_error(
        self,
        h_values,
        exact_derivative,
        x
    ):

        forward_errors = []
        backward_errors = []
        central_errors = []
        richardson_errors = []

        exact = exact_derivative(x)

        for h in h_values:

            # Forward Difference

            result = self.forward.calculate(h)

            forward_errors.append(
                abs(exact - result)
            )


            # Backward Difference

            result = self.backward.calculate(h)

            backward_errors.append(
                abs(exact - result)
            )


            # Central Difference

            result = self.central.calculate(h)

            central_errors.append(
                abs(exact - result)
            )


            # Richardson Extrapolation

            result = self.richardson.calculate(h)

            richardson_errors.append(
                abs(exact - result)
            )


        # -----------------------------------------
        # Create graph
        # -----------------------------------------

        plt.figure()

        plt.loglog(
            h_values,
            forward_errors,
            marker="o",
            label="Forward Difference"
        )

        plt.loglog(
            h_values,
            backward_errors,
            marker="o",
            label="Backward Difference"
        )

        plt.loglog(
            h_values,
            central_errors,
            marker="o",
            label="Central Difference"
        )

        plt.loglog(
            h_values,
            richardson_errors,
            marker="o",
            label="Richardson Extrapolation"
        )


        plt.xlabel("Step Size (h)")

        plt.ylabel("Absolute Error")

        plt.title(
            "Numerical Differentiation Error Comparison"
        )

        plt.grid(True)

        plt.legend()

        plt.show()


    # -----------------------------------------
    # Lagrange Interpolation Graph
    # -----------------------------------------

    def plot_lagrange(
        self,
        function,
        x_values,
        y_values
    ):

        # Find minimum and maximum x values

        min_x = min(x_values)
        max_x = max(x_values)


        # Create graph x values

        graph_x = []

        current = min_x - 1

        while current <= max_x + 1:

            graph_x.append(current)

            current = current + 0.01


        # -----------------------------------------
        # Original function values
        # -----------------------------------------

        function_y = []

        for value in graph_x:

            function_y.append(
                function(value)
            )


        # -----------------------------------------
        # Create Lagrange polynomial
        # -----------------------------------------

        polynomial = self.lagrange.calculate(
            x_values,
            y_values
        )


        # -----------------------------------------
        # Evaluate Lagrange polynomial
        # -----------------------------------------

        lagrange_y = []

        for value in graph_x:

            result = self.lagrange.evaluate(
                polynomial,
                value
            )

            lagrange_y.append(result)


        # -----------------------------------------
        # Create graph
        # -----------------------------------------

        plt.figure()


        # Original function

        plt.plot(
            graph_x,
            function_y,
            label="Original Function"
        )


        # Lagrange polynomial

        plt.plot(
            graph_x,
            lagrange_y,
            label="Lagrange Polynomial"
        )


        # Known data points

        plt.scatter(
            x_values,
            y_values,
            label="Known Data Points"
        )


        plt.xlabel("x")

        plt.ylabel("y")

        plt.title(
            "Lagrange Interpolation"
        )

        plt.legend()

        plt.grid(True)

        plt.show()


    # -----------------------------------------
    # Newton Divided Difference Graph
    # -----------------------------------------

    def plot_newton(
        self,
        function,
        x_values,
        y_values
    ):

        # Find minimum and maximum x values

        min_x = min(x_values)

        max_x = max(x_values)


        # -----------------------------------------
        # Create graph x values
        # -----------------------------------------

        graph_x = []

        current = min_x - 1

        while current <= max_x + 1:

            graph_x.append(current)

            current = current + 0.01


        # -----------------------------------------
        # Original function values
        # -----------------------------------------

        function_y = []

        for value in graph_x:

            function_y.append(
                function(value)
            )


        # -----------------------------------------
        # Newton polynomial values
        # -----------------------------------------

        newton_y = []

        for value in graph_x:

            result = self.newton.evaluate(
                x_values,
                y_values,
                value
            )

            newton_y.append(result)


        # -----------------------------------------
        # Create graph
        # -----------------------------------------

        plt.figure()


        # Original function

        plt.plot(
            graph_x,
            function_y,
            label="Original Function"
        )


        # Newton polynomial

        plt.plot(
            graph_x,
            newton_y,
            label="Newton Polynomial"
        )


        # Known data points

        plt.scatter(
            x_values,
            y_values,
            label="Known Data Points"
        )


        plt.xlabel("x")

        plt.ylabel("y")

        plt.title(
            "Newton Divided Difference Interpolation"
        )

        plt.legend()

        plt.grid(True)

        plt.show()
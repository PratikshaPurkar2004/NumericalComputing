from numericalIntegration import NumericalIntegration


class Trapezoidal(NumericalIntegration):

    def trapezoidal(self, n):

        h = self.calculate_h(n)

        result = (
            self.function(self.lower)
            + self.function(self.upper)
        )

        for i in range(1, n):

            x = self.lower + i * h

            result += 2 * self.function(x)

        return (h / 2) * result
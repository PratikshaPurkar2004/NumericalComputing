from numericalIntegration import NumericalIntegration


class SimpsonOneThird(NumericalIntegration):

    def simpsonOneThird(self, n):

        if n % 2 != 0:
            raise ValueError("Simpson 1/3 requires n to be even.")

        h = self.calculate_h(n)

        result = (self.function(self.lower) + self.function(self.upper))

        for i in range(1, n):
            x = self.lower + i * h
            if i % 2 == 0:
                result += 2 * self.function(x)
            else:
                result += 4 * self.function(x)

        return (h / 3) * result
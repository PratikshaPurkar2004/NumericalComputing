from numericalIntegration import NumericalIntegration


class SimpsonThreeEight(NumericalIntegration):

    def simpsonThreeEight(self, n):

        if n % 3 != 0:
            raise ValueError("Simpson 3/8 requires n to be ""a multiple of 3.")

        h = self.calculate_h(n)

        result = ( self.function(self.lower) + self.function(self.upper))

        for i in range(1, n):
            x = self.lower + i * h
            if i % 3 == 0:
                result += 2 * self.function(x)
            else:
                result += 3 * self.function(x)

        return (3 * h / 8) * result
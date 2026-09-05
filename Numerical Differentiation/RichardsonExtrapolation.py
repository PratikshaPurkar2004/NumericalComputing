from numericalDiff import NumericalDifferentiation
from CentralDifference import CentralDifference


class RichardsonExtrapolation(NumericalDifferentiation):

    def calculate(self, h):

        central = CentralDifference(
            self.function,
            self.exact_derivative,
            self.x
        )

        D_h = central.calculate(h)

        D_h2 = central.calculate(h / 2)

        result = (4 * D_h2 - D_h) / 3

        return result
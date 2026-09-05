from numericalDiff import NumericalDifferentiation


class CentralDifference(NumericalDifferentiation):

    def calculate(self, h):

        result = (
            self.function(self.x + h)
            - self.function(self.x - h)
        ) / (2 * h)

        return result
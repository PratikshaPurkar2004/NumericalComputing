from numericalDiff import NumericalDifferentiation


class BackwardDifference(NumericalDifferentiation):

    def calculate(self, h):

        result = (
            self.function(self.x)
            - self.function(self.x - h)
        ) / h

        return result
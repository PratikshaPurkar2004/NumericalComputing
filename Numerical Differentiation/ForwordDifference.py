from numericalDiff import NumericalDifferentiation


class ForwardDifference(NumericalDifferentiation):

    def calculate(self, h):

        result = (
            self.function(self.x + h)
            - self.function(self.x)
        ) / h

        return result
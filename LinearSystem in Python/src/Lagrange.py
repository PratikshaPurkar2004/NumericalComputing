from Interpolation import Interpolation


class Lagrange(Interpolation):
    def __init__(self, n1=0):
        super().__init__(n1)

    def solve(self, xp):
        if self.rows == 0:
            raise Exception("No data points")

        yp = 0.0

        for i in range(self.rows):
            L = 1.0

            for j in range(self.rows):
                if i != j:
                    if self.a[i][0] == self.a[j][0]:
                        raise Exception("duplicate x values")

                    L *= (xp - self.a[j][0]) / (self.a[i][0] - self.a[j][0])

            yp += L * self.a[i][1]

        return yp

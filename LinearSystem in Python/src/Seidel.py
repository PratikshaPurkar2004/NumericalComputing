import math
from Iteration import Iteration


class Seidel(Iteration):
    def __init__(self, n):
        super().__init__(n)

    def solve(self, max_iter=100, tol=1e-6):
        n = self.rows
        x = [0.0] * n

        for iteration in range(max_iter):
            old = x[:]

            for i in range(n):
                if self.a[i][i] == 0:
                    raise Exception("Zero diagonal in Seidel")

                s = self.a[i][n]
                for j in range(n):
                    if i != j:
                        s -= self.a[i][j] * x[j]
                x[i] = s / self.a[i][i]

            err = 0.0
            for i in range(n):
                err += abs(x[i] - old[i])

            if err < tol:
                return x[:]

        return x

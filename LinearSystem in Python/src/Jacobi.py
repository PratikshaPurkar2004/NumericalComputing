import math
from Iteration import Iteration


class Jacobi(Iteration):
    def __init__(self, n):
        super().__init__(n)

    def solve(self, max_iter=100, tol=1e-6):
        n = self.rows
        x = [0.0] * n
        x_new = [0.0] * n

        w = 0.5

        for iteration in range(max_iter):
            for i in range(n):
                if self.a[i][i] == 0:
                    print(f"Warning: zero diagonal at row {i}")
                    x_new[i] = x[i]
                    continue

                s = self.a[i][n]
                for j in range(n):
                    if i != j:
                        s -= self.a[i][j] * x[j]

                xi = s / self.a[i][i]
                x_new[i] = (1 - w) * x[i] + w * xi

            err = 0.0
            for i in range(n):
                err += abs(x_new[i] - x[i])

            if err < tol:
                return x_new[:]

            x = x_new[:]

        return x

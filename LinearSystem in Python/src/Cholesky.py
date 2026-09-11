import math
from LUDecomposition import LUDecomposition


class Cholesky(LUDecomposition):
    def __init__(self, sz):
        super().__init__(sz)

    def solve(self):
        n = self.rows

        if not self.is_symmetric():
            raise Exception("Matrix not symmetric")

        L = [[0.0] * n for _ in range(n)]

        for i in range(n):
            for j in range(i + 1):
                s = 0.0
                for k in range(j):
                    s += L[i][k] * L[j][k]

                if i == j:
                    if self.a[i][i] - s <= 0:
                        raise Exception("Matrix not positive definite")
                    L[i][j] = math.sqrt(self.a[i][i] - s)
                else:
                    if L[j][j] == 0:
                        raise Exception("Division by zero in Cholesky")
                    L[i][j] = (self.a[i][j] - s) / L[j][j]

        y = [0.0] * n
        x = [0.0] * n

        # Ly = b
        for i in range(n):
            y[i] = self.a[i][n]
            for j in range(i):
                y[i] -= L[i][j] * y[j]
            if L[i][i] == 0:
                raise Exception("Division by zero")
            y[i] /= L[i][i]

        # L^T x = y
        for i in range(n - 1, -1, -1):
            x[i] = y[i]
            for j in range(i + 1, n):
                x[i] -= L[j][i] * x[j]
            if L[i][i] == 0:
                raise Exception("Division by zero")
            x[i] /= L[i][i]

        return x

from LUDecomposition import LUDecomposition


class Crout(LUDecomposition):
    def __init__(self, sz):
        super().__init__(sz)

    def solve(self):
        n = self.rows
        L = [[0.0] * n for _ in range(n)]
        U = [[0.0] * n for _ in range(n)]

        for i in range(n):
            U[i][i] = 1.0

        for j in range(n):
            for i in range(j, n):
                s = 0.0
                for k in range(j):
                    s += L[i][k] * U[k][j]
                L[i][j] = self.a[i][j] - s

            for i in range(j + 1, n):
                s = 0.0
                for k in range(j):
                    s += L[j][k] * U[k][i]
                if L[j][j] == 0:
                    raise Exception("Zero pivot in Crout")
                U[j][i] = (self.a[j][i] - s) / L[j][j]

        y = [0.0] * n
        x = [0.0] * n

        # Ly = b
        for i in range(n):
            y[i] = self.a[i][n]
            for j in range(i):
                y[i] -= L[i][j] * y[j]
            if L[i][i] == 0:
                raise Exception("Division by zero in Crout")
            y[i] /= L[i][i]

        # Ux = y
        for i in range(n - 1, -1, -1):
            x[i] = y[i]
            for j in range(i + 1, n):
                x[i] -= U[i][j] * x[j]
            if U[i][i] == 0:
                raise Exception("Division by zero in Crout")
            x[i] /= U[i][i]

        return x

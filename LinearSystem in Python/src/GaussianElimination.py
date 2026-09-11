import math
from LinearSystem import LinearSystem


class GaussianElimination(LinearSystem):
    def __init__(self, sz):
        super().__init__(sz)

    def pivot(self, k):
        raise NotImplementedError

    def forward_elimination(self):
        for k in range(self.rows):
            self.pivot(k)
            if abs(self.a[k][k]) < 1e-12:
                raise Exception("zero pivot")
            for i in range(k + 1, self.rows):
                factor = self.a[i][k] / self.a[k][k]
                for j in range(k, self.cols):
                    self.a[i][j] -= factor * self.a[k][j]

    def back_substitution(self):
        x = [0.0] * self.rows
        for i in range(self.rows - 1, -1, -1):
            x[i] = self.a[i][self.cols - 1]
            for j in range(i + 1, self.rows):
                x[i] -= self.a[i][j] * x[j]
            x[i] /= self.a[i][i]
        return x


class WithoutPivot(GaussianElimination):
    def __init__(self, sz):
        super().__init__(sz)

    def pivot(self, k):
        pass

    def solve(self):
        self.forward_elimination()
        return self.back_substitution()


class PartialPivot(GaussianElimination):
    def __init__(self, sz):
        super().__init__(sz)

    def pivot(self, k):
        max_row = k
        for i in range(k + 1, self.rows):
            if abs(self.a[i][k]) > abs(self.a[max_row][k]):
                max_row = i
        if max_row != k:
            self.a[k], self.a[max_row] = self.a[max_row], self.a[k]

    def solve(self):
        self.forward_elimination()
        return self.back_substitution()

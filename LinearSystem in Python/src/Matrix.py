import math
import copy


class Matrix:
    def __init__(self, rows=0, cols=0):
        self.rows = rows
        self.cols = cols
        self.a = [[0.0] * cols for _ in range(rows)]

    def copy(self):
        m = Matrix(self.rows, self.cols)
        m.a = [row[:] for row in self.a]
        return m

    def read_from_file(self, fin):
        """Read matrix values from an open file (token by token)."""
        tokens = []
        for line in fin:
            tokens.extend(line.split())
        idx = 0
        for i in range(self.rows):
            for j in range(self.cols):
                self.a[i][j] = float(tokens[idx])
                idx += 1

    def resize(self, r, c):
        self.rows = r
        self.cols = c
        self.a = [[0.0] * c for _ in range(r)]

    def display_to_file(self, fout):
        print("solution")
        for i in range(self.rows):
            fout.write(" ".join(str(self.a[i][j]) for j in range(self.cols)) + "\n")

    def __add__(self, m):
        if self.rows != m.rows or self.cols != m.cols:
            raise Exception("Matrix size mismatch")
        result = Matrix(self.rows, self.cols)
        for i in range(self.rows):
            for j in range(self.cols):
                result.a[i][j] = self.a[i][j] + m.a[i][j]
        return result

    def __sub__(self, m):
        if self.rows != m.rows or self.cols != m.cols:
            raise Exception("Matrix size mismatch")
        result = Matrix(self.rows, self.cols)
        for i in range(self.rows):
            for j in range(self.cols):
                result.a[i][j] = self.a[i][j] - m.a[i][j]
        return result

    def __mul__(self, m):
        if self.cols != m.rows:
            raise Exception("Matrix size mismatch")
        result = Matrix(self.rows, m.cols)
        for i in range(self.rows):
            for j in range(m.cols):
                for k in range(self.cols):
                    result.a[i][j] += self.a[i][k] * m.a[k][j]
        return result

    def __call__(self, i, j):
        return self.a[i][j]

    def set(self, i, j, val):
        self.a[i][j] = val

    def __eq__(self, m):
        if self.rows != m.rows or self.cols != m.cols:
            return False
        for i in range(self.rows):
            for j in range(self.cols):
                if self.a[i][j] != m.a[i][j]:
                    return False
        return True

    def __str__(self):
        result = ""
        for i in range(self.rows):
            result += " ".join(str(self.a[i][j]) for j in range(self.cols)) + "\n"
        return result

    def is_square(self):
        return self.rows == self.cols

    def is_symmetric(self):
        if not self.is_square():
            return False
        for i in range(self.rows):
            for j in range(self.cols):
                if self.a[i][j] != self.a[j][i]:
                    return False
        return True

    def is_identity(self):
        for i in range(self.rows):
            for j in range(self.cols):
                if i == j and self.a[i][j] != 1:
                    return False
                if i != j and self.a[i][j] != 0:
                    return False
        return True

    def is_null(self):
        for i in range(self.rows):
            for j in range(self.cols):
                if self.a[i][j] != 0:
                    return False
        return True

    def is_diagonal(self):
        for i in range(self.rows):
            for j in range(self.cols):
                if i != j and self.a[i][j] != 0:
                    return False
        return True

    def is_diagonally_dominant(self):
        for i in range(self.rows):
            s = 0.0
            for j in range(self.rows):
                if i != j:
                    s += abs(self.a[i][j])
            if abs(self.a[i][i]) <= s:
                return False
        return True

    def is_transpose(self, m):
        if self.rows != m.cols or self.cols != m.rows:
            return False
        for i in range(self.rows):
            for j in range(self.cols):
                if self.a[i][j] != m.a[j][i]:
                    return False
        return True

    def make_diagonally_dominant(self):
        for i in range(self.rows):
            max_row = i
            for k in range(i + 1, self.rows):
                if abs(self.a[k][i]) > abs(self.a[max_row][i]):
                    max_row = k
            self.a[i], self.a[max_row] = self.a[max_row], self.a[i]

    def transpose(self):
        t = Matrix(self.cols, self.rows)
        for i in range(self.rows):
            for j in range(self.cols):
                t.a[j][i] = self.a[i][j]
        return t

    def determinant(self):
        if self.rows != self.cols:
            raise Exception("Matrix must be square")
        temp = self.copy()
        det = 1.0
        for k in range(self.rows):
            if abs(temp.a[k][k]) < 0:
                return 0
            for i in range(k + 1, self.rows):
                factor = temp.a[i][k] / temp.a[k][k]
                for j in range(k, self.rows):
                    temp.a[i][j] -= factor * temp.a[k][j]
        for i in range(self.rows):
            det *= temp.a[i][i]
        return det

    def inverse(self):
        if self.rows != self.cols:
            raise Exception("Inverse only for square matrix")
        inv = Matrix(self.rows, self.cols)
        temp = self.copy()
        for i in range(self.rows):
            inv.a[i][i] = 1.0
        for i in range(self.rows):
            pivot = temp.a[i][i]
            if pivot == 0:
                raise Exception("Matrix is singular")
            for j in range(self.rows):
                temp.a[i][j] /= pivot
                inv.a[i][j] /= pivot
            for k in range(self.rows):
                if k == i:
                    continue
                factor = temp.a[k][i]
                for j in range(self.cols):
                    temp.a[k][j] -= factor * temp.a[i][j]
                    inv.a[k][j] -= factor * inv.a[i][j]
        return inv

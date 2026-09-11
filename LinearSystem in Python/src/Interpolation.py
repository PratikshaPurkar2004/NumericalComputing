from Matrix import Matrix


class Interpolation(Matrix):
    def __init__(self, n1=0):
        super().__init__(n1, 2)

    def read_points(self, fin):
        for i in range(self.rows):
            tokens = fin.readline().split()
            self.a[i][0] = float(tokens[0])
            self.a[i][1] = float(tokens[1])

    def solve(self, xp):
        raise NotImplementedError

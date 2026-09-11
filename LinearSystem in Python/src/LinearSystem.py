from Matrix import Matrix


class LinearSystem(Matrix):
    def __init__(self, sz):
        super().__init__(sz, sz + 1)

    def solve(self):
        raise Exception("solve() not implemented")

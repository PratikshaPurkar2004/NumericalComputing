from Matrix import Matrix


class Eigen(Matrix):
    def __init__(self, n=0):
        super().__init__(n, n)

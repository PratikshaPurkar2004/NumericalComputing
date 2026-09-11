import math
from CurveFitting import CurveFitting
from Matrix import Matrix


class LeastSquare(CurveFitting):
    def __init__(self, n):
        super().__init__(n)

    def fit_polynomial(self, fout, degree):
        n = self.size()

        if degree >= n:
            raise Exception("Degree must be less than number of points")

        X = Matrix(n, degree + 1)
        Y = Matrix(n, 1)

        for i in range(n):
            x = self.a[i][0]
            y = self.a[i][1]

            for j in range(degree + 1):
                X.a[i][j] = math.pow(x, j)

            Y.a[i][0] = y

        Xt = X.transpose()
        A = (Xt * X).inverse() * Xt * Y

        fout.write("POLYNOMIAL FIT \n")
        fout.write(f"Degree = {degree}\n")

        fout.write("y = ")
        for i in range(degree + 1):
            coeff = A.a[i][0]

            if i == 0:
                fout.write(f"{coeff:.4f}")
            else:
                if coeff >= 0:
                    fout.write(f" + {coeff:.4f}x^{i}")
                else:
                    fout.write(f" - {abs(coeff):.4f}x^{i}")

        fout.write("\n")

        sum_error_sq = 0.0

        for i in range(n):
            x = self.a[i][0]
            y = self.a[i][1]

            yhat = 0.0
            for j in range(degree + 1):
                yhat += A.a[j][0] * math.pow(x, j)

            err = y - yhat
            sum_error_sq += err * err

        rms = math.sqrt(sum_error_sq / n)

        fout.write(f"\nRMS Error = {rms:.4f}\n")

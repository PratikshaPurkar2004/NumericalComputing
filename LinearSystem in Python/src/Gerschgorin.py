import math
from Eigen import Eigen


class Gerschgorin(Eigen):
    def __init__(self, n=0):
        super().__init__(n)

    def find_discs(self, fout, tol=1e-6):
        fout.write("\n========== GERSCHGORIN DISCS ==========\n\n")

        for i in range(self.rows):
            center = self.a[i][i]
            radius = 0.0

            for j in range(self.cols):
                if i != j and abs(self.a[i][j]) > tol:
                    radius += abs(self.a[i][j])

            fout.write(f"Disc {i+1:3d}:\n")
            fout.write("----------------------------------\n")
            fout.write(f"Center (a[{i+1},{i+1}]) : {center:10.4f}\n")
            fout.write(f"Radius                        : {radius:10.4f}\n")
            fout.write(f"Region: |z - ({center:.4f})| <= {radius:.4f}\n")
            fout.write(f"Approx Eigenvalue             : {center:.4f}\n")
            fout.write("----------------------------------\n\n")

        fout.write("=======================================\n")

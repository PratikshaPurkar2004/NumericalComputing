from GaussianElimination import PartialPivot
from Crout import Crout
from Doolittle import Doolittle
from Cholesky import Cholesky
from Jacobi import Jacobi
from Seidel import Seidel
from Gerschgorin import Gerschgorin
from Lagrange import Lagrange
from LeastSquare import LeastSquare


def read_tokens(filepath):
    """Read all tokens from a file and return as list of strings."""
    tokens = []
    with open(filepath, 'r') as f:
        for line in f:
            tokens.extend(line.split())
    return tokens


def main():
    left_file = "../49/49l.txt"
    right_file = "../49/49r.txt"
    output_file = "../output.txt"

    try:
        left_tokens = read_tokens(left_file)
        right_tokens = read_tokens(right_file)
    except FileNotFoundError:
        print("File error")
        return 1

    fout = open(output_file, 'w')

    print("\n1. Gaussian\n2. Doolittle\n3. Crout\n4. Cholesky\n5. Jacobi\n6. Seidel\n7. Lagrange\n8. Least Square")
    choice = int(input("Enter choice: "))

    # Read dimensions from left file
    idx = 0
    r = int(left_tokens[idx]); idx += 1
    c = int(left_tokens[idx]); idx += 1

    # Gerschgorin Discs
    g = Gerschgorin(r)
    for i in range(r):
        for j in range(c):
            g.a[i][j] = float(left_tokens[idx]); idx += 1

    fout.write("\nGerschgorin Discs\n")
    g.find_discs(fout)
    fout.write(f"Choice = {choice}\n")

    # Reset index to re-read matrix for solver
    idx = 2  # skip r, c

    if choice == 1:
        solver = PartialPivot(r)
    elif choice == 2:
        solver = Doolittle(r)
    elif choice == 3:
        solver = Crout(r)
    elif choice == 4:
        solver = Cholesky(r)

    elif choice == 5:
        jb = Jacobi(r)

        for i in range(r):
            for j in range(c):
                jb.a[i][j] = float(left_tokens[idx]); idx += 1

        ridx = 0
        for i in range(r):
            jb.a[i][c] = float(right_tokens[ridx]); ridx += 1

        try:
            x = jb.solve(1000, 0.000001)
            fout.write("Jacobi Solution\n")
            for i in range(r):
                fout.write(f"x{i+1} = {x[i]}\n")
        except Exception as e:
            print(f"Error: {e}")
            fout.write(f"Error: {e}\n")

        fout.close()
        return 0

    elif choice == 6:
        sd = Seidel(r)

        for i in range(r):
            for j in range(c):
                sd.a[i][j] = float(left_tokens[idx]); idx += 1

        ridx = 0
        for i in range(r):
            sd.a[i][c] = float(right_tokens[ridx]); ridx += 1

        x = sd.solve(1000, 0.000001)

        fout.write("Seidel Solution\n")
        for i in range(r):
            fout.write(f"x{i+1} = {x[i]}\n")

        fout.close()
        return 0

    elif choice == 7:
        try:
            with open("../points.txt", 'r') as fin:
                n = int(fin.readline().strip())
                lg = Lagrange(n)
                lg.read_points(fin)
        except FileNotFoundError:
            print("Points file error")
            fout.close()
            return 0

        xp = float(input("Enter value to interpolate: "))
        result = lg.solve(xp)

        fout.write("Lagrange Interpolation\n")
        fout.write(f"Value at x = {xp} is {result}\n")

        fout.close()
        return 0

    elif choice == 8:
        try:
            with open("../points.txt", 'r') as fin:
                n = int(fin.readline().strip())
                ls = LeastSquare(n)
                ls.read_points(fin)
        except FileNotFoundError:
            print("Points file error")
            fout.close()
            return 0

        degree = int(input("Enter degree: "))

        try:
            ls.fit_polynomial(fout, degree)
        except Exception as e:
            print(e)

        fout.close()
        return 0

    else:
        print("Invalid choice")
        fout.close()
        return 0

    # For choices 1-4: load augmented matrix and solve
    solver.resize(r, c + 1)

    for i in range(r):
        for j in range(c):
            solver.a[i][j] = float(left_tokens[idx]); idx += 1

    ridx = 0
    for i in range(r):
        solver.a[i][c] = float(right_tokens[ridx]); ridx += 1

    try:
        x = solver.solve()
        fout.write("Solution\n")
        for i in range(r):
            fout.write(f"x{i+1} = {x[i]}\n")
    except Exception as e:
        fout.write(f"Error: {e}\n")

    fout.close()
    return 0


if __name__ == "__main__":
    main()

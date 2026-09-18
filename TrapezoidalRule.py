import math

# Function
def f(x):
    return x * x


# Limits
a = 0
b = 2

# Exact value
exact_value = 8 / 3

# Number of trapezoids
n_values = [1, 2, 4, 8, 16]

# Print table heading
print("+----+--------+-----------------------+----------------+--------------------+")
print("| n  |   h    | Numerical Approximation| Absolute Error | Order of Accuracy  |")
print("+----+--------+-----------------------+----------------+--------------------+")

previous_error = None

for n in n_values:

    # Step size
    h = (b - a) / n

    # First and last values
    total = f(a) + f(b)

    # Middle values
    for i in range(1, n):
        x = a + i * h
        total = total + 2 * f(x)

    # Trapezoidal Rule
    approximation = (h / 2) * total

    # Absolute error
    error = abs(exact_value - approximation)

    # Order of accuracy
    if previous_error is None:
        order = "-"
    else:
        order = math.log(previous_error / error, 2)

    # Print each row
    if order == "-":
        print(f"| {n:<2} | {h:<6.3f} | {approximation:<21.6f} | {error:<14.6f} | {order:<18} |")
    else:
        print(f"| {n:<2} | {h:<6.3f} | {approximation:<21.6f} | {error:<14.6f} | {order:<18.2f} |")

    # Save current error
    previous_error = error

# Bottom line
print("+----+--------+-----------------------+----------------+--------------------+")

print("\nExact value =", exact_value)
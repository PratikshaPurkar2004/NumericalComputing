import math

def f(x):
    return x * x

a = 0
b = 2

exact_value = 8 / 3

n_values = [1, 2, 4, 8, 16]


print("+----+--------+-----------------------+----------------+--------------------+")
print("| n  |   h    | Numerical Approximation| Absolute Error | Order of Accuracy  |")
print("+----+--------+-----------------------+----------------+--------------------+")

previous_error = None

for n in n_values:
    h = (b - a) / n
    total = f(a) + f(b)

    for i in range(1, n):
        x = a + i * h
        total = total + 2 * f(x)

    approximation = (h / 2) * total
    error = abs(exact_value - approximation)
    if previous_error is None:
        order = "-"
    else:
        order = math.log(previous_error / error, 2)

    if order == "-":
        print(f"| {n:<2} | {h:<6.3f} | {approximation:<21.6f} | {error:<14.6f} | {order:<18} |")
    else:
        print(f"| {n:<2} | {h:<6.3f} | {approximation:<21.6f} | {error:<14.6f} | {order:<18.2f} |")

    previous_error = error

print("+----+--------+-----------------------+----------------+--------------------+")

print("\nExact value =", exact_value)
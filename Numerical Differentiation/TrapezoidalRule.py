import matplotlib.pyplot as plt

def f(x):
    return x**2

def exact_integral(a, b):
    return (b**3 - a**3) / 3

a = float(input("Enter lower limit a: "))
b = float(input("Enter upper limit b: "))

exact = exact_integral(a, b)

n_values = [2, 4, 6, 8, 10]

error_values = []


print("\nTRAPEZOIDAL RULE")
print("-" * 70)
print(f"{'n':<10}{'h':<15}{'IT':<15}{'Exact':<15}{'Error':<15}")
print("-" * 70)


for n in n_values:
    h = (b - a) / n
    total = f(a) + f(b)
    for i in range(1, n):
        x = a + i * h
        total = total + 2 * f(x)
    IT = (h / 2) * total

    error = abs(exact - IT)

    error_values.append(error)

    print(f"{n:<10}{h:<15.6f}{IT:<15.6f}"
          f"{exact:<15.6f}{error:<15.6f}")


# GRAPH 

plt.plot(n_values, error_values, marker='o')

plt.xlabel("Number of intervals (n)")
plt.ylabel("Absolute Error")

plt.title("Trapezoidal Rule - Error vs n")

plt.grid(True)

plt.show()
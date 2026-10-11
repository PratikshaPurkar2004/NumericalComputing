
from eigenValues import EigenValues


class PowerMethod(EigenValues):
    def solve(self, initial_vector, tolerance=1e-6,
              max_iterations=100):

        vector = initial_vector[:]
        eigenvalue = 0

        for iteration in range(1, max_iterations + 1):

            # Multiply matrix by the current vector
            new_vector = self.matrix_vector_multiply(vector)

            # Find the largest absolute component
            scale = max(abs(x) for x in new_vector)

            if scale == 0:
                raise ValueError(
                    "Power Method cannot continue with a zero vector."
                )

            # Normalize the vector
            new_vector = [x / scale for x in new_vector]

            # Calculate the eigenvalue using the Rayleigh quotient
            av = self.matrix_vector_multiply(new_vector)

            numerator = sum(
                new_vector[i] * av[i]
                for i in range(self.n)
            )

            denominator = sum(
                x * x for x in new_vector
            )

            new_eigenvalue = numerator / denominator

            if abs(new_eigenvalue - eigenvalue) < tolerance:
                vector = new_vector
                eigenvalue = new_eigenvalue
                break

            vector = new_vector
            eigenvalue = new_eigenvalue

        return eigenvalue, vector, iteration

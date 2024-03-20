#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int n) {
    bool *prime = (bool *)malloc((n+1) * sizeof(bool));
    for (int i = 0; i <= n; i++)
        prime[i] = true;

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are:\n", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");

    free(prime);
}

int main() {
    int n;
    printf("Enter the number n: ");
    scanf("%d", &n);

    sieve_of_eratosthenes(n);

    return 0;
}

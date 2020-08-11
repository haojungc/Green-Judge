#include <stdio.h>

long long int k[100];

void get_ways(int max_stairs) {
    /* Fibonacci sequence */
    k[0] = k[1] = 1;
    for (int i = 2; i <= max_stairs; i++)
        k[i] = k[i - 1] + k[i - 2];
}

int main() {
    int n; /* the number of stairs */

    scanf("%d", &n);

    get_ways(n);

    printf("%lld %lld\n", k[n], k[k[n] % n]);

    return 0;
}
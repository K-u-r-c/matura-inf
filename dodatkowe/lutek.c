//Kombinacja np. 4 ze 100

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double factorial(int n) {
    double silnia = 1;

    for(double i = (double)n; i > 1; i--) {
        silnia *= i;
    }

    return silnia;
}

char combination(int N, int K) {
    double n_factorial, k_factorial, nk_factorial, result;

    n_factorial = factorial(N);
    k_factorial = factorial(K);
    nk_factorial = factorial(N-K);

    result = n_factorial / (k_factorial * nk_factorial);

    if(fmod(result, 2) < 0.00001) {
        return 'P';
    } else {
        return 'N';
    }
}

int main(int argc, char** argv) {
    int d;
    int N, K;

    while(1) {
        printf("Enter d: ");
        scanf("%d", &d);

        if(d >= 1 && d <= 10000000) {
            break;
        } else {
            printf("Wrong d format d >= 1 and d <= 10000000\n");
        }
    }

    char result[d];

    for(int i = 0; i < d; i++) {
        while(1) {
            printf("Enter N and K: ");
            scanf("%d %d", &N, &K);

            if(N >= 0 && K >= 0) {
                break;
            } else {
                printf("Wrong N and K format N, K >= 0");
            }
        }

        if(K > N) {
            result[i] = 'E';
        } else result[i] = combination(N, K);
    }

    for(int i = 0; i < d; i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//p - początek
void sortowanie_naiwne(int T[], int p, int n) {
	int pom, i;
	i = p;

	while (i < p + n  - 1) {
		if (T[i] > T[i + 1]) {
			pom = T[i];
			T[i] = T[i + 1];
			T[i + 1] = pom;

            i = p;

            continue;
		}

		i++;
	}
}

int main(int argc, char** argv) {
    srand(time(NULL));
	int T[100];

	for(int i = 0; i < 100; i++) {
		T[i] = rand() % 150 + 100;
		printf("%d %d \n", i, T[i]);
	}

	sortowanie_naiwne(T, 0, 100);

    for (int i = 0; i < 100; i++) {
        printf("%d %d \n", i, T[i]);
	}

    return 0;
}
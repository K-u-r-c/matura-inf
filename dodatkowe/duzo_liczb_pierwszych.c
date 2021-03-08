//wyznaczanie wszystkich liczb pierwszych do n oraz zapisanie ich do pliku

#include <stdio.h>
#include <stdlib.h>

enum { ARG_NAME, ARG_N, ARG_OUTFILE, ARG_ARGC };

void sito_eratostenesa(int n, int* tab) {
    for(int i = 2; i * i <= n; i++)
        if(!tab[i])
            for(int j = i * i; j <= n; j += i)
                tab[j] = 1;
}

int main(int argc, char** argv) {
    int n = 0, i;
    FILE* output;

    if(argc != ARG_ARGC) {
        printf("Usage: name n outfile.txt\n");
        return 1;
    }

    n = atoi(argv[ARG_N]);
    if(n <= 0) {
        printf("Wrong n format n must be greater than 0");
        return 1;
    }

    int tab[n + 1];
    for(i = 0; i <= n; i++)
        tab[i] = 0;

    output = fopen(argv[ARG_OUTFILE], "w");
    if(output == NULL) {
        printf("Was not able to open file %s", argv[ARG_OUTFILE]);
        return 1;
    }

    sito_eratostenesa(n, tab);

    for(i = 2; i <= n; i++)
        if(!tab[i]) fprintf(output, "%d\n", i);

    fclose(output);

    return 0;
}
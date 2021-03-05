//Sortowanie przez zliczanie

#include <iostream>
#include <time.h>

void sortowanie_przez_zliczanie(int T[], int p, int q, int min, int max) {
    int* pom;
    int licznik = 0, i;

    pom = new (std::nothrow) int [max - min + 1];

    if(pom == nullptr) std::cout << ":( 404 Tutaj powinna byc Twoja ulubiona tablica ";
    for (i = 0; i < max - min; i++) pom[i] = 0; //zerujemy elementy tablicy

    for(i = p; i <= q; i++)
        for(int k = 0; k <= max - min; k++)
            if((T[i] - min) == k) {
                pom[k]++;
                break;
            }

    while(licznik <= max - min) {
        while (pom[licznik] > 0) {
            T[p] = licznik + min;
            
            pom[licznik]--;
            p++;
        }
        licznik++;
    }

    delete [] pom;
}

int main(int argc, char** argv) {
    srand(time(NULL));
	int T[100];

    for(int i = 0; i <= 50; i++) {
		T[i] = rand() % 150 + 100;
		std::cout << i << " " << T[i] << std::endl;
	}

    sortowanie_przez_zliczanie (T, 0, 50, 100, 249);
	
    for (int i = 0; i <= 50; i++)
		std::cout << i << " " << T[i] << std::endl;

    return 0;
}
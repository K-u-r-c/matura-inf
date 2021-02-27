//Sortowanie przez wstawianie liniowe

#include <iostream>

void sortowanie(int *tab, int n) {
    int element = 0, j = 0;

    for(int i = 1; i < n; i++) {
        element = tab[i];

        j = i - 1;

        while(j >= 0 && tab[j] > element) {
            tab[j + 1] = tab[j];

            j--;
        }

        tab[j + 1] = element;
    }
}

int main(int argc, char** argv) {
    int n = 0; //ilosc elementow tablicy

    while(1) {
        std::cout << "Podaj ilosc elementow tablicy: "; std::cin >> n;

        if(n > 0) break;
    }

    int tab[n];

    for(int i = 0; i < n; i++) {
        std::cout << "Podaj " << i << " element tablicy: "; 
        std::cin >> tab[i];
    }

    sortowanie(tab, n);

    for(int i = 0; i < n; i++) {
        std::cout << tab[i] << " "; 
    }

    std::cout << std::endl;

    return 0;
}
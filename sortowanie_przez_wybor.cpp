//Sortowanie tablicy poprzez wybieranie

#include <iostream>

void sortowanie(int* tab, int n) {
    int min_i;

    for(int i = 0; i < n; i++) {
        min_i = i; //przypisz index minimum poczatkowi przeszukiwanego zbioru

        for(int j = i; j < n; j++) {
            if(tab[min_i] > tab[j]) min_i = j; //Jesli znaleziono nowy najmniejszy element zapamietaj jego index
        }

        std::swap(tab[min_i], tab[i]);
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
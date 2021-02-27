//Sortowanie szybkie, implementacja z pivotem na srodku sortowanego zbioru

#include <iostream>

void sortowanie(int *tab, int lewy, int prawy) {
    if(prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1;

    int pivot = tab[(lewy + prawy) / 2]; //wybieramy srodkowy element tablicy

    while(1) {
        while(pivot > tab[++i]);
        while(pivot < tab[--j]);

        if(i <= j) std::swap(tab[i], tab[j]);
        else break;
    }

    if(j > lewy) sortowanie(tab, lewy, j);
    if(i < prawy) sortowanie(tab, i, prawy);
}

int main(int argc, char** argv) {
    int n = 0; //ilosc elementow tablicy
    int *tab; //tablica do posortowania

    while(1) {
        std::cout << "Podaj ilosc elementow tablicy: "; std::cin >> n;

        if(n > 0) break;
    }

    tab = new int[n];

    for(int i = 0; i < n; i++) {
        std::cout << "Podaj " << i << " element tablicy: "; 
        std::cin >> tab[i];
    }

    sortowanie(tab, 0, n - 1);

    for(int i = 0; i < n; i++) {
        std::cout << tab[i] << " "; 
    }

    std::cout << std::endl;

    return 0;
}
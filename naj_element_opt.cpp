//Jednoczesne znalezienie najmniejszego i najwiekszego elementu zbioru [metoda optymalna].

#include <iostream>

void min_max(int tab[], int n) {
    int min = tab[0], max = tab[0], i = 0;

    while(i + 2 <= n) {
        if(tab[i] > tab[i + 1]) {
            if(tab[i] > max) max = tab[i];
            if(tab[i + 1] < min) min = tab[i + 1];
        } else {
            if(tab[i] < min) min = tab[i];
            if(tab[i + 1] > max) max = tab[i + 1];
        }

        i += 2;
    }
    
    if(n % 2 == 1) {
        if(tab[i] > max) max = tab[i];
        if(tab[i] < min) min = tab[i];
    }

    std::cout << "MIN: " << min << " | MAX: " << max << std::endl;
}

int main(int argc, char** argv) {
    int n = 0; //ilosc elementow zbioru

    while(true) {
        std::cout << "Podaj ilosc elementow zbioru: "; std::cin >> n;

        if(n > 1 && n < 100) break;
    }

    int tab[n];

    for(int i = 0; i < n; i++) {
        while(true) {
            std::cout << "Podaj " << i << " element zbioru: ";
            std::cin >> tab[i];

            if(tab[i] >= 0 && tab[i] < 1000) break;
        }
    }

    min_max(tab, n);

    return 0;
}
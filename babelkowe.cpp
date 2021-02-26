//Sortowanie babelkowe

#include <iostream>

void babelkowe(int tab[], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            if(tab[j - 1] > tab[j])
                std::swap(tab[j - 1], tab[j]);
}

int main(int argc, char** argv) {
    int n;

    while(true) {
        std::cout << "Podaj liczbe elementow: ";
        std::cin >> n;   

        if(n > 0 && n < 100) break;
    }

    int tab[n];

    for(int i = 0; i < n; i++) {
        while(true) {
            std::cout << "Podaj wartosc elementu " << i << " tablicy: "; std::cin >> tab[i]; 

            if(i < 1000 && i > -1000) break;           
        }
    }

    babelkowe(tab, n);

    for(int i = 0; i < n; i++) {
        std::cout << " " << tab[i] << " ";
    }

    return 0;
}
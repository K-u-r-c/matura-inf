//Sortowanie przez scalanie

#include <iostream>

int *p_tab;

void scalanie(int *tab, int lewy, int prawy, int srodek) {
    int i, j;
    
    //lewa podtablica do tablicy pomocniczej
    for(i = srodek + 1; i > lewy; i--)
        p_tab[i - 1] = tab[i - 1];

    //prawa podtablica do tablicy pomocniczej
    for(j = srodek; j < prawy; j++)
        p_tab[prawy + srodek - j] = tab[j + 1];

    //scalenie tablic pomocniczych w tablicy glownej
    for(int k = lewy; k <= prawy; k++)
        p_tab[j] < p_tab[i] ? tab[k] = p_tab[j--] : tab[k] = p_tab[i++]; 
}

void sortowanie(int *tab, int lewy, int prawy) {
    if(prawy == lewy) return; //sprawdzenie czy pozostal juz tylko jeden element

    int srodek = (lewy + prawy) / 2; //miejsce w ktorym tablica zostanie przedzielona

    sortowanie(tab, lewy, srodek); //przekazujemy lewa czesc tablicy
    sortowanie(tab, srodek + 1, prawy); //przekazujemy prawa czesc tablicy

    scalanie(tab, lewy, prawy, srodek); //dwie posortowane tablice
}

int main(int argc, char** argv) {
    int n = 0; //ilosc elementow tablicy
    int *tab;

    while(1) {
        std::cout << "Podaj ilosc elementow tablicy: "; std::cin >> n;

        if(n > 0) break;
    }

    tab = new int[n];
    p_tab = new int[n];

    for(int i = 0; i < n; i++) {
        std::cout << "Podaj " << i << " element tablicy: "; 
        std::cin >> tab[i];
    }

    sortowanie(tab, 0, n - 1); //lewy to pierwszy element tablicy | prawy to ostatni element tablicy

    for(int i = 0; i < n; i++) {
        std::cout << tab[i] << " "; 
    }

    std::cout << std::endl;

    return 0;
}
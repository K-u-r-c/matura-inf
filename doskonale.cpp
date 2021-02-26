//Sprawdzanie czy liczba jest liczba doskonala

#include <iostream>

char doskonala(int liczba) {
    int suma_dzielnikow = 0;

    for(int i = 1; i < liczba; i++)
        if(liczba % i == 0) suma_dzielnikow += i;

    if(suma_dzielnikow == liczba) return 'T';
    else return 'N';
}

int main(int argc, char** argv) {
    int liczba = 0;

    while(1) {
        std::cout << "Podaj liczbe: ";
        std::cin >> liczba;

        if(liczba > 0) break;
    }

    std::cout << "Wynik: " << doskonala(liczba) << std::endl;

    return 0;
}

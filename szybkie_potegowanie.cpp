//Szybkie podnoszenie do potegi

#include <iostream>

long long pow(long long podstawa, int wykladnik) {
    long long wynik = 1;

    while(wykladnik > 0) {
        if(wykladnik % 2 == 1) wynik *= podstawa; //Jesli bit jest rowny 1 to wynik przemnazamy przez aktualna wartosc podstawy

        podstawa *= podstawa;
        wykladnik /= 2; //skracamy wykladnik o 1 bit
    }

    return wynik;
}

int main(int argc, char** argv) {
    long long podstawa;
    unsigned int wykladnik;

    std::cout << "Podaj podstawe: ";
    std::cin >> podstawa;

    while(1) {
        std::cout << "Podaj wykladnik: ";
        std::cin >> wykladnik;

        if(wykladnik >= 0 && wykladnik < 10000) break;
    }

    std::cout << podstawa << "^" << wykladnik << " = " << pow(podstawa, wykladnik) << std::endl;

    return 0;
}
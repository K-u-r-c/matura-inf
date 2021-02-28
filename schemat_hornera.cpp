//Obliczanie wartosci wielomianu schematem hornera

#include <iostream>

int schemat_hornera(int* wspolczynniki, int stopien, int x) {
    int wynik = wspolczynniki[0];

    for(int i = 1; i < stopien; i++)
        wynik = wynik * x + wspolczynniki[i];

    return wynik;
}

int main(int argc, char** argv) {
    int* wspolczynniki; //Stojace przy x-ach
    int stopien, x; //Stopien pierwiastka aka najwieksza potega | wartosc x

    while(1) {
        std::cout << "Podaj stopien wielomianu: "; 
        std::cin >> stopien;

        if(stopien >= 0 && stopien < 10) break;
    }

    wspolczynniki = new int[stopien + 1]; //+1 bo jeszcze wyraz wolny

    for(int i = 0; i <= stopien; i++) {
        std::cout << "Podaj wspolczynnik stojacy przy potedze " << stopien - i << ": ";
        std::cin >> wspolczynniki[i];
    }

    if(stopien > 0) {
        std::cout << "Podaj wartosc x: ";
        std::cin >> x;
    }

    std::cout << "\nWynik: " << schemat_hornera(wspolczynniki, stopien, x) << std::endl;

    return 0;
}
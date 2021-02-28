//Znajdowanie miejsca zerowego funkcji metoda polowienia przedzialow (metoda bisekcji lub metoda rownego podzialu)
//program w tym przypadku szuka mz dla wielomianu 3x^3 - 6x^2 + 3x - 1

#include <iostream>

#define epsilon 0.00001

double F(double x) {
    return x * (x * (3 *x - 6.0) + 3.0) - 1.0; //ze schematu hornera
}

double polowienie_przedzialow(double a, double b) {
    if(F(a) == 0.0) return a;
    if(F(b) == 0.0) return b;

    double srodek;

    while(b - a > epsilon) {
        srodek = (a + b) / 2.0;

        if(F(srodek) == 0.0) return srodek;

        if(F(a) * F(srodek) < 0.0) b = srodek;
        else a = srodek;
    }

    return (a + b) / 2.0;
}

int main(int argc, char** argv) {
    double a = -10.0, b = 10.0;

    std::cout << "MZ: " << polowienie_przedzialow(a, b) << std::endl;

    return 0;
}
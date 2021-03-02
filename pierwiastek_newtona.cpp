//Wyliczanie pierwiastka z liczby metoda Newtona

#include <iostream>
#include <cmath>

#define epsilon 0.000001

double pierwiastek(double P) {
    if (P == 0) return 0;
    
    double a = 1.0, b = P;
    
    while(fabs(a - b) >= epsilon) {
        a = (a + b) / 2.0;
        b = P / a;
    }

    return a;
}

int main(int argc, char** argv) {
    double liczba = 0;

    while(1) {
        std::cout << "Podaj liczbe: "; std::cin >> liczba;

        if(liczba >= 0) break;
    }

    std::cout << "\nPierwiastek: " << pierwiastek(liczba) << std::endl;

    return 0;
}
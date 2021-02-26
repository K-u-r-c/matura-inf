//Rozklad liczby na czynniki pierwsze

#include <iostream>
#include <cmath>

void rozklad(int liczba) {
    int p = 2;
    float pierwiastek = sqrt(liczba);

    while(liczba > 1 && p <= pierwiastek) {
        while(liczba % p == 0) {
            std::cout << p << " ";
            liczba /= p;
        }
        p++;
    }

    if(liczba > 1) std::cout << liczba << std::endl;
}

int main(int argc, char** argv) {
    unsigned int liczba = 0;

    while(1) {
        std::cout << "Podaj liczbe: ";
        std::cin >> liczba;

        if(liczba > 0) {
            break;
        }
    }
    rozklad(liczba);

    return 0;
}

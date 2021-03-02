//Sprawdzanie czy slowo to palindrom

#include <iostream>
#include <string.h>

bool palindrom(char tab[]) {
    int i = 0, j = strlen(tab) - 1;

    while(i < j) {
        if(tab[i] != tab[j]) return false;

        i++;
        j--;
    }

    return true;
}

int main(int argc, char** argv) {
    char wyraz[100];

    std::cout << "Podaj wyraz: ";
    std::cin >> wyraz;

    if(palindrom(wyraz))
        std::cout << "TAK \n";
    else 
        std::cout << "NIE \n";

    return 0;
}
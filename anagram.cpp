//Sprawdzanie czy podane slowa sa anagramami

#include <iostream>
#include <stdio.h>
#include <string.h>

void sort_wyraz(char* wyraz, int n) {
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n-1; j++)
            if(wyraz[j] > wyraz[j+1])
                std::swap( wyraz[j], wyraz[j+1]);
}

bool anagram(char wyraz1[], char wyraz2[]) {
    int d_wyraz1 = strlen(wyraz1), d_wyraz2 = strlen(wyraz2);

    if( d_wyraz1 != d_wyraz2) return false;

    sort_wyraz(wyraz1, d_wyraz1);
    sort_wyraz(wyraz2, d_wyraz2);

    for(int i = 0; i < d_wyraz1; i++)
        if(wyraz1[i] != wyraz2[i]) return false;
    
    return true;
}

int main(int argc, char** argv) {
    char wyraz1[100], wyraz2[100];

    std::cout << "Podaj wyraz 1 i wyraz 2: ";
    std::cin >> wyraz1 >> wyraz2;

    anagram(wyraz1, wyraz2) ? std::cout << "TAK" << std::endl : std::cout << "NIE" << std::endl;

    return 0;
}
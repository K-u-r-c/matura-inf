//Wyszukiewanie wzorca w tekscie

#include <iostream>
#include <string.h>

void wyszukiwanie_wzorca(char slowo[], char fraza[]) {
    int d_slowo = strlen(slowo), d_fraza = strlen(fraza);
    int index_frazy = 0, i;
    bool znaleziono_fraze = false;

    for(i = 0; i < d_slowo; i++) {
        if(slowo[i] != fraza[index_frazy]) {
            index_frazy = 0;
            continue;
        }

        if(index_frazy == d_fraza-1) {
            znaleziono_fraze = true;
            break;
        }

        index_frazy++;
    }
    
    znaleziono_fraze ? std::cout<< "Znaleziono fraze " << fraza << " na " << i-index_frazy << " pozycji\n" : std::cout<< "Nie znaleziono \n";
}

int main(int argc, char** argv) {
    char slowo[100], fraza[100];
    std::cout << "Podaj slowo: ";
    std::cin >> slowo;
    std::cout << "Podaj szukana fraze: ";
    std::cin >> fraza;

    wyszukiwanie_wzorca(slowo, fraza);

    return 0;
}
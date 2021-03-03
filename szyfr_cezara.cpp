//

#include <iostream>

std::string szyfruj(std::string slowo, std::string alfabet, int k) {
    k %= alfabet.length();
    std::string wynik = "";
    
    for(int i = 0; i < slowo.length() ; i++) {
        if(char(slowo[i]) == 32) wynik += " ";
        else {
            slowo[i] = tolower(slowo[i]);
            for(int j = 0; j < alfabet.length(); j++)
                if(slowo[i] == alfabet[j]){
                    wynik += alfabet[(j + k) % alfabet.length()];
                    break;
                }
        }
    }
    return wynik;
}

int main(int argc, char** argv) {
    int k;    
    std::string slowo;
    std::string alfabet = "abcdefghijklmnopqrstuvwxyz";

    std::cout << "Podaj slowo: ";
    std::getline(std::cin, slowo);

    std::cout << "Podaj klucz: ";
    std::cin >> k;

    std::cout << szyfruj(slowo, alfabet, k) << std::endl;

    return 0;
}
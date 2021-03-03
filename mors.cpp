//Tłumaczenie tekstu na alfabet Morse'a

#include <iostream>

std::string slownik[26] = {
    ".-", "-...", "-.-.", "-..", ".", ".-..", "--.", "....", "..", ".---",
    "-.-", "..-.", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

std::string tlumacz(std::string slowo) {
    std::string wynik = "";

    for(int i = 0; i < slowo.length(); i++)
        wynik += slownik[char(std::tolower(slowo[i]) - 97)] + "/";

    return wynik;
}

int main(int argc, char** argv) {
    std::string wyrazenie;

    std::cout<< "Podaj wyrazenie do zaszyfrowania: ";
    std::cin >> wyrazenie;
    
    std::cout << "Kodem Morse'a: " << tlumacz(wyrazenie) << std::endl;

    return 0;
}
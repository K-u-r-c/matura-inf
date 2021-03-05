//Szyfr przestawieniowy

#include <iostream>

std::string szyfr(std::string slowo) {
    int d_slowo = slowo.length();

    for(int i = 0; i < d_slowo - 1; i += 2) {
        std::swap(slowo[i], slowo[i + 1]);
    }
    
    return slowo;
}

int main(int argc, char** argv) {
    std::string slowo;

    std::cout << "Podaj wyraz do zaszyfrowania: ";
    std::cin >> slowo;    

    std::cout << "Zaszyfrowane: " << szyfr(slowo) << std::endl;

    return 0;
}
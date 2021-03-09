#include <iostream>

int little_endian_convert(unsigned int hex_liczba) {
    int wynik;
    int bajty[4];
    
    std::cout << "small endian: ";
    
    for(int i = 3; i >= 0; i--) {
        bajty[i] = hex_liczba % 256;
        hex_liczba /= 256;
        
        if(bajty[i] < 10) std::cout << "0";
        std::cout << std::hex << bajty[i] << " ";
    }
    
    std::cout << "\nbig endian: ";
    
    for(int i = 0; i < 4; i++) {
        if(bajty[i] < 10) std::cout << "0";
        std::cout << std::hex << bajty[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}

int main(int argc, char** argv) {
    unsigned int liczba = 0;

    std::cout << "Podaj liczbe: ";
    std::cin >> std::hex >> liczba;

    little_endian_convert(liczba);
    
    return 0;
}
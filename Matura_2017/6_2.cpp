#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::fstream plik("dane.txt");

    int wiersz[320];

    int nie_palindrom = 0;

    for(int i = 0; i < 200; i++) {
        for(int z = 0; z < 320; z++) plik >> wiersz[z];
        for(int k = 0; k < 160; k++) {
            if(wiersz[k] != wiersz[319 - k]) {
                nie_palindrom++;
                break;
            }
        }
    }
    
    
    plik.close();
    
    std::cout << "Wynik " << nie_palindrom << std::endl;
    
    return 0;
}
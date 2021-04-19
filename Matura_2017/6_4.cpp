#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::fstream plik("dane.txt");
    
    int ciag = 1, max_ciag = 0;

    int piksele[200][320];

    for(int i = 0; i < 200; i++)
        for(int z = 0; z < 320; z++) plik >> piksele[i][z];


    for(int poziom = 0; poziom < 320; poziom++) {
        ciag = 1;
        for(int pion = 1; pion < 200; pion++) {
            if(piksele[pion][poziom] == piksele[pion-1][poziom]) {
                ciag++;
                if(ciag > max_ciag) max_ciag = ciag;
            } else ciag = 1;
        }
    }
    
    plik.close();

    std::cout << "Wynik: " << max_ciag << std::endl;
    return 0;
}
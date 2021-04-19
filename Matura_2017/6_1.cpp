#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::fstream plik("dane.txt");
    
    int kolor;
    int kolor_min = 255, kolor_max = 0;

    for(int i = 0; i < 200; i++)
        for(int z = 0; z < 320; z++) {
            plik >> kolor;
            if(kolor < kolor_min) kolor_min = kolor;
            else if(kolor > kolor_max) kolor_max = kolor;
        }

    std::cout << "najjasniejszy: " << kolor_max << "\tnajciemniejszy: " << kolor_min << std::endl; 
    
    plik.close();
    
    return 0;
}
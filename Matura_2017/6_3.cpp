#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::fstream plik("dane.txt");
    
    bool sa_czy_nie[200][320];
    for(int i = 0; i < 200; i++)
        for(int z = 0; z < 320; z++) sa_czy_nie[i][z] = false;

    int piksele[200][320];

     for(int i = 0; i < 200; i++)
        for(int z = 0; z < 320; z++) plik >> piksele[i][z];

     for(int i = 0; i < 199; i++){
         for(int z = 0; z < 319; z++){
             if(abs(piksele[i][z] - piksele[i][z + 1]) > 128){
                 sa_czy_nie[i][z] = true;
                 sa_czy_nie[i][z + 1] = true;
             } // w prawo
             if(abs(piksele[i][z] - piksele[i + 1][z]) > 128){
                 sa_czy_nie[i][z] = true;
                 sa_czy_nie[i + 1][z] = true;
             } // w dół
         }
          if(abs(piksele[i][319] - piksele[i + 1][319]) > 128){
                 sa_czy_nie[i][319] = true;
                 sa_czy_nie[i + 1][319] = true;
             } // w dół
     }

     for(int z = 0; z < 319; z++)
             if(abs(piksele[199][z] - piksele[199][z + 1]) > 128){
                 sa_czy_nie[199][z] = true;
                 sa_czy_nie[199][z + 1] = true; 
                } // lewa - prawa ostatni wiersz

    int ile = 0;

    for(int i = 0; i < 200; i++)
        for(int z = 0; z < 320; z++) if(sa_czy_nie[i][z] == true) ile++;
    plik.close();
    std::cout << "Wynik " << ile << std::endl;
    return 0;
}
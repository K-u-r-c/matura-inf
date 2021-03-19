#include <iostream>

typedef struct {
    int waga;
    int wartosc;
} przedmiot;

int max(int a, int b) {return (a > b) ? a : b;}

void dynamiczny_plecakowy(int n, int waga, przedmiot *przedmioty) {
    int tab[waga + 1];
    
    for(int i = 0; i <= waga; i++) tab[i] = 0;

    for(int i = 0; i <= waga; i++)
        for(int j = 0; j < n; j++)
            if(przedmioty[j].waga  <= i)
                tab[i] = max(tab[i], tab[i - przedmioty[j].waga] + przedmioty[j].wartosc);
        
    std::cout << waga  << " " << tab[waga] << "\t";
}


int main(int argc, char** argv) {
    przedmiot przedmioty[5];
    
    przedmioty[0].waga = 111;
    przedmioty[1].waga = 121;
    przedmioty[2].waga = 131;
    przedmioty[3].waga = 141;
    przedmioty[4].waga = 151;
    przedmioty[0].wartosc = 11;
    przedmioty[1].wartosc = 22;
    przedmioty[2].wartosc = 33;
    przedmioty[3].wartosc = 44;
    przedmioty[4].wartosc = 55;

    dynamiczny_plecakowy(5, 300, przedmioty);
    std::cout << std::endl;

    return 0x80;
}
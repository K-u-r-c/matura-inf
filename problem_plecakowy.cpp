//Problem plecakowy
//konflikt 2 parametrów, pierwszy chcemy max, drugi na min np. max kalorii w plecaku na górską wycieczkę, przy minimum wagi
// można optymalizować po jednym parametrze, po drugim lub po współczynniku

#include <iostream>
#include <cmath>
#include <ctime>

typedef struct {
    double waga;
    int wartosc;
    double stosunek;
} przedmiot;

typedef struct {
    double waga;
    int wartosc;
} plecaczek;

void sortowanie(int n, przedmiot *p) {
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            if(p[j - 1].stosunek < p[j].stosunek)
                std::swap(p[j - 1], p[j]);
}

plecaczek zachlannie(int n, przedmiot *p, double max_waga) {
    double waga_plecaka = 0; //aktualna waga
    int wartosc_plecaka = 0;
    for(int i = 0; i < n; i++) {
        while(p[i].waga <= max_waga - waga_plecaka) {
            waga_plecaka += p[i].waga;
            wartosc_plecaka += p[i].wartosc;
        } //zabieramy item
        if(waga_plecaka == max_waga) break;
    }
    
    plecaczek wynikowy;
    wynikowy.waga = waga_plecaka;
    wynikowy.wartosc = wartosc_plecaka;
    
    return wynikowy;
}

int main(int argc, char** argv) {
    double max_waga_plecaka = 145.8;
    przedmiot przedmioty[20];
    srand(time(NULL));
    
    for(int i = 0; i < 20; i++) {
        przedmioty[i].waga = (rand() % 75 + 1);
        przedmioty[i].waga = przedmioty[i].waga / (double)(rand() % 15 + 1);
        przedmioty[i].wartosc = rand() % 24 + 1;
        przedmioty[i].stosunek = (double)przedmioty[i].wartosc / (double)przedmioty[i].waga;
    }
    
    sortowanie(20, przedmioty);
    
    plecaczek wynik = zachlannie(20, przedmioty, max_waga_plecaka);
    std::cout << wynik.wartosc << std::endl;
    std::cout << wynik.waga << std::endl;
    
    return 0;
} 
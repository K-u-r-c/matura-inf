#include<iostream>
#include<ctime>
#include <cstdlib>

void sortowanie(double *tab, int lewy, int prawy) {
    if(prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1;

    int pivot = tab[(lewy + prawy) / 2]; //wybieramy srodkowy element tablicy

    while(1) {
        while(pivot > tab[++i]);
        while(pivot < tab[--j]);

        if(i <= j) std::swap(tab[i], tab[j]);
        else break;
    }

    if(j > lewy) sortowanie(tab, lewy, j);
    if(i < prawy) sortowanie(tab, i, prawy);
}

int wyszukiwanie_binarne(double *tab, int lewy, int prawy, double szukana)
{
    if(lewy <= prawy){
        int srodek = (lewy + prawy) / 2;
        if(tab[srodek] == szukana) return srodek;
        else if (tab[srodek] > szukana) return(tab, lewy, srodek - 1, szukana);
        return(tab, srodek+1, prawy, szukana);
    }
    return -1;
}

int main(int argc, char** argv) {
    srand(time(NULL));
	double T[100];

    for(int i = 0; i <= 50; i++) {
		T[i] = rand() % 150 + 100;
		std::cout << i << " " << T[i] << std::endl;
	}

    sortowanie(T, 0, 50);
	
    for (int i = 0; i <= 50; i++)
		std::cout << i << " " << T[i] << std::endl;

    std::cout << "Podaj wartosc: ";
    double n;
    std::cin >> n;
    std::cout << "\n" << wyszukiwanie_binarne(T, 0, 50, n);

    return 0;
}
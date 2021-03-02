//Obliczanie wartosci wyrazenia podanego w odwrotnej notacji polskiej

#include <iostream>
#include <stack>
#include <string.h>

bool cyfra(char znak) {
	return (znak >= '0' && znak <= '9');
}

bool oper(char znak) {
	return (znak == '+' || znak == '-' || znak == '*' || znak == '/');
}

int policz(int war1, int war2, char oper) {
	if (oper == '+') return war1 + war2;
	if (oper == '-') return war1 - war2;
	if (oper == '*') return war1 * war2;
	return war1 / war2;
}

int main(int argc, char** argv) {
    std::stack<int> stos;
    std::string wyrazenie, liczba;

    std::cout << "Podaj wyrazenie: ";
    std::getline(std::cin, wyrazenie);
    
    int n = wyrazenie.length();

    for(int i = 0; i < n; i++) {
        if(wyrazenie[i] == ' ' && liczba != "") {
            stos.push(stoi(liczba));
            liczba = "";
        } else if(cyfra(wyrazenie[i]))
            liczba += wyrazenie[i];
        else if(oper(wyrazenie[i])) {
            int a, b;
            a = stos.top(); //2 operator
            stos.pop();

            b = stos.top(); //1 operator
            stos.pop();

            stos.push(policz(b, a, wyrazenie[i]));
        }
    }

    stos.size() != 1 ? std::cout << "Podano zly zestaw RPN\n" : std::cout << "Wynik wyrazenia to: " << stos.top() << std::endl;

    return 0;
}
//Całkowanie numeryczne - metoda trapezów

#include <iostream>
#include <stdio.h>

double F(int x) {
    return x * x + x * 2;
}

double pole(int a, int b, int n) {
    double h = (b - a) / (double)n, podst_a = F(a), podst_b;
    double suma = 0;

    for(int i = 1; i <= n; i++) {
        podst_b = F(a + h * i);
        suma += podst_a + podst_b;
        podst_a = podst_b;
    }

    return suma * 0.5 * h;
}

int main(int argc, char** argv) {
    int a = 0, b = 0, n = 0;

    while(1) {
        std::cout << "Podaj przedzial (a - b) oraz wartosc n: ";
        scanf("%d %d %n", &a, &b, &n);

        if(b > a) break;
        else {
            std::cout << "Podano zly przedzial\n";
        }
    }

    std::cout << "Pole obszaru wynosi: " << pole(a, b, n) << std::endl;

    return 0;
}
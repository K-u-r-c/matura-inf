//całkowanie numeryczne metodą prostokątów

#include <iostream>

double F(double x) {
    return x * x + x * 2; // Taka tam sobie funkcja kwadratowa 
}

double metoda_prostokatow(double p, double q, int n) {
    double dl = (q - p) / (double)n;
    double pole = 0;

    for(int i = 1; i <= n; i++) {
        pole += abs(F(p + dl * i - dl / 2)); // -dl/2, bo chcemy mierzyć "w połowie"
    }

    return pole * dl;
}

int main(int argc, char** argv) {
    std::cout << metoda_prostokatow(5, 10, 1000) << std::endl;    
    
    return 0;
}
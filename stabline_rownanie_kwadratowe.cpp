//Stabilne wyznaczanie miejsc zerowych funkcji kwadratowej

#include <iostream>
#include <math.h>

// Podaj a, b, c: 0.000001 1 0.00003

int main(int argc, char** argv) {
    float a, b, c;

    std::cout << "Podaj a, b, c: ";
    std::cin >> a >> b >> c;

    float delta = b * b - 4 * a * c;
    if(delta >= 0) {
        float x1, x2;

        if(b >= 0) {
            x1 = (-b - sqrt(delta)) / 2 * a;
            x2 = c / (0.5 * (-b - sqrt(delta)));
        } else {
            x1 = (-b + sqrt(delta)) / 2 * a;
            x2 = c / (0.5 * (-b + sqrt(delta)));
        }

        std::cout << "x1: " << x1 << " \nx2: " << x2 << std::endl;
    } else std::cout << "delta < 0\n";
    
    return 0;
}
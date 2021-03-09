//Wyznaczanie n poczatkowych wyrazow ciagu fibonacciego

#include <iostream>
#include <iomanip>

void fibonacci(int n) {
    long double a = 0, b = 1;

    for(int i = 0; i <= n; i++) {
        std::cout << i << ": " << std::setprecision(0) << std::fixed << b << " \n";
        b += a;
        a = b - a;
    }
}

int main(int argc, char** argv) {
    int n;

    while(1) {
        std::cout << "Podaj ilosc wyrazow ciagu: "; std::cin >> n;

        if(n <= 23600) break;
    }

    fibonacci(n);

    return 0;
}

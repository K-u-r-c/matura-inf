/* Sprawdzanie warunku trójkąta (czy z podanych boków można zbudować trójkąt) */

#include <iostream>

bool mozna(int a, int b, int c) {
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}

int main(int argc, char** argv) {
    int a, b, c;

    std::cout << "Podaj a b c: ";
    std::cin >> a >> b >> c;

    mozna(a, b, c) ? std::cout << "Mozna !\n" : std::cout << "Nie mozna :(\n";

    return 0;
}
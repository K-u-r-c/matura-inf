#include <iostream>

 void wieze_hanoi(char a, char b, char c, int n)
{
    if(n > 0){
        wieze_hanoi(a, c, b, n - 1);
        std::cout << a << " na " << b << std::endl;
        wieze_hanoi(c, b, a, n - 1);
    }
}

int main(int argc, char** argv){
    int n;
    std::cout << "Podaj n ";
    std::cin >> n;
    wieze_hanoi('a', 'b', 'c', n);
    return 0;
}
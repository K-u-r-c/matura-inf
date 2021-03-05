#include <stdio.h>

int x, y;

void euklides_rozsz(int a, int b);

void euklides_rozsz(int a, int b) {
    int pomoc;

    if(b != 0) {
        euklides_rozsz(b, a % b);

        pomoc = y;
        y = x - (a / b) * y;
        x = pomoc;
    }
}

int main(int argc, char** argv) {
    int a, b;

    x = 1, y = 0;
    
    scanf("%d %d", &a, &b);

    euklides_rozsz(a, b);

    printf("NWD = %d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    
    return 0;
}
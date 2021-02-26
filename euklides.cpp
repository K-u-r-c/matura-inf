//Wyznaczanie NWD 2 liczb

#include <stdio.h>
#include <utility>

int euklides(int l1, int l2) {    
    while(l2) std::swap(l1 %= l2, l2);

    return l1;
}

int main(int argc, char** argv) {
    int l1, l2;

    printf("Podaj liczby l1 oraz l2: ");
    scanf("%d %d", &l1, &l2);

    if(l1 == 0 && l2 == 0) return 1;

    printf("%d\n", euklides(l1, l2));

    return 0;
}

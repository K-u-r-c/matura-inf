#include<stdio.h>
#include<stdlib.h>

unsigned long long silnia_rekurencyjna(int n){
    if(n == 0) return 1;
    else return n * silnia_rekurencyjna(n - 1);
}

int main(int argc, char** argv)
{
    silnia_rekurencyjna(atoi(argv[1]));
    return 0x80;
}
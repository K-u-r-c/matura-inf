#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double factorial(double x) {
    int i;
    double wynik = 1;

    if(x == 1) {
        return 1;
    }

    for(i = x; i > 1; i--) {
        wynik *= i;
    }

    return wynik;
}

int contains(char* arr, char a) {
    for(int i = 0; i < strlen(arr); i++) {
        if(a == arr[i]) {
            return 1;
        }
    }

    return 0;
}

int count_repeats(char* word, char c) {
    int count = 0;
    for(int i = 0; i < strlen(word); i++) {
        if(c == word[i]) count++;
    }

    return count;
}

char* find_repeats(char* word) {
    char str[256] = "";
    char* s_ptr = str;

    for(int i = 0; i < strlen(word); i++) {
        if(!contains(str, word[i])) {
            strncat(str, &word[i], 1);  
        }              
    }

    return s_ptr;    
}

double words(int word_length, double den) {
    double result;

    result = factorial(word_length) / den;

    return result;
}

int main(int argc, char* argv[]) {
    double den = 1;
    char* str;

    if(argc != 2) {
        printf("Error: wrong number of characters\n");
        printf("usage: wyr [word]\n");
        return 1;
    }

    str = find_repeats(argv[1]);

    int repeats[strlen(str)];

    char tmp[strlen(str)+1];

    strcpy(tmp, str);

    //build repeats array
    for(int i = 0; i < strlen(tmp); i++) {
        //printf("%d, %c\n", count_repeats(argv[1], tmp[i]), tmp[i]);
        repeats[i] = count_repeats(argv[1], tmp[i]);
    }

    //calc denominator
    for(int i = 0; i < strlen(tmp); i++) {
        den *= factorial(repeats[i]);
    }

    //printf("%d\n", den);

    printf("number of words possible to be created from word [%s] is %.0lf ", argv[1], words(strlen(argv[1]), den));

    return 0;
}
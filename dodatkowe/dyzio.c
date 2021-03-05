/*Wyznaczanie liczn pierwszych z przedzialu.
Potrzebuje pliku input.txt wygladajacego np tak:
	0
	2 100
	5 50
	6 16
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a, b;
} przedzial;

int check_for_prime_numbers(int a, int b)
{
    int prime_numbers = 0, dividers = 0;

    for(int number = a; number <= b; number++)
    {
        if(number < 2) continue;
        if(number % 2 == 0 && number != 2) continue;

        for(int divide = 2; divide < number; divide++) 
        {
            if(number % divide == 0) 
            {
                dividers++;
                break;
            }
        }
        if (dividers > 0)
        {
            dividers = 0;
        } 
        else 
        {
            prime_numbers++;
        }
    }

    return prime_numbers;
}

int main(int argc, char** argv) 
{
    FILE* input;
    char line[99];
    przedzial p;  
    
    input = fopen("input.txt", "r");
    
    if(input == NULL) {
        perror("Program was not able to open input file");
        return 1;
    }

    while(fgets(line, 99, input) != NULL)
    {
        fscanf(input, "%d %d" , &p.a, &p.b);
        printf("primal numbers in <%d, %d> = %d\n", p.a, p.b, check_for_prime_numbers(p.a, p.b));
    }

    fclose(input);

    return 0;
}

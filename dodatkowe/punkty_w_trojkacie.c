/*Czy punkty leza wewnatrz na granicy czy poza trojkatem.
Potrzebuje pliku input.txt wygladajacego np tak:

630 421 326 242 561 432 478 332
378 212 380 550 840 735 379 381
591 916 765 191 487 490 678 554
975 75 324 166 343 28 650 120
0 0 0 0 0 0 0 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { ARG_NAME, ARG_INPUT, ARG_OUTPUT, ARG_ARGC };

typedef struct {
    int x, y;
} point;

int check_if_number(char c) {
    return c > 47 && c < 58;
}

point make_point(int coordinates[], int n) {
    point points[4];

    points[n].x = coordinates[2 * n];
    points[n].y = coordinates[2 * n + 1];

    return points[n];
}

double calculate_triangle_area(point P1, point P2, point P3) {
    double area = 0.0f;
    double x1 = (double)P1.x, 
    x2 = (double)P2.x, 
    x3 = (double)P3.x, 
    y1 = (double)P1.y, 
    y2 = (double)P2.y, 
    y3 = (double)P3.y;

    double n1 = y2 - y3,
    n2 = y3 - y1,
    n3 = y1 - y2;

    area = ((x1 * n1) + (x2 * n2) + (x3 * n3)) / 2;

    if(area < 0) {
        return area * -1;
    } else {
        return area;
    }
}

char check_point_position(int coordinates[]) {
    point A, B, C, P;
    double area1, area2, area3, total_area;

    A = make_point(coordinates, 0);
    B = make_point(coordinates, 1);
    C = make_point(coordinates, 2);
    P = make_point(coordinates, 3);

    total_area = calculate_triangle_area(A, B, C);
    area1 = calculate_triangle_area(P, A, B);
    area2 = calculate_triangle_area(P, B, C);
    area3 = calculate_triangle_area(P, A, C);

    if(area1 == 0 || area2 == 0 || area3 == 0) {
        return 'E';
    } else if(area1 + area2 + area3 == total_area) {
        return 'I';
    } else {
        return 'O';
    }
}

int main(int argc, char** argv) {
    const int n = 8;
    int points[n], i = 0, line_count = 0;
    char number[99] = "";
    char ch;
    
    FILE* input;
    FILE* output;

    if(argc != ARG_ARGC) {
        printf("USAGE: trojkat input.txt output.txt\n");
        return 1;
    }

    input = fopen(argv[ARG_INPUT], "r");

    if(input == NULL) {
        printf("Program was not able to read %s file", argv[ARG_INPUT]);
        return 1;
    }
    
    while((ch = fgetc(input)) != EOF) {
        if(check_if_number(ch)) {
            strncat(number, &ch, 1);
        } else if(ch == '\n') { //new line
            points[i] = atoi(number);
            strcpy(number, "");
            i = 0;

            if(line_count > 0){
                output = fopen(argv[ARG_OUTPUT], "a");
            } else output = fopen(argv[ARG_OUTPUT], "w");

            if(output == NULL) {
                printf("Program was not able to write to %s", argv[ARG_OUTPUT]);
                return 1;
            }
            
            fprintf(output, "%c\n", check_point_position(points));
            printf("RESULT: %c\n", check_point_position(points));
            
            fclose(output);
            line_count ++;
        } else {
            points[i] = atoi(number);
            strcpy(number, "");
            i++;
        }        
    }

    fclose(input);

    return 0;
}

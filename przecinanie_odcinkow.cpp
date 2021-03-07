//Sprawdzanie czy odcinki się przecinają

#include <iostream>

typedef struct {
    int x, y;
} punkt;

int iloczyn_wektorowy(punkt p1, punkt p2, punkt p3) {
    int wx1 = p3.x - p1.x,
    wy1 = p3.y - p1.y,
    wx2 = p2.x - p1.x,
    wy2 = p2.y - p1.y;

    return wx1 * wy2 - wx2 * wy1;
}

bool punkt_na_odcinku(punkt A, punkt B, punkt C, int iloczny_w) {
    return iloczny_w == 0 && C.x >= std::min(A.x, B.x) && C.x <= std::max(A.x, B.x) && C.y >= std::min(A.y, B.y) && C.y <= std::max(A.y, B.y);
}

bool przecinaja(punkt A, punkt B, punkt C, punkt D) {
    int iloczyn_w1 = iloczyn_wektorowy(A, B, C),
    iloczyn_w2 = iloczyn_wektorowy(A, B, D),
    iloczyn_w3 = iloczyn_wektorowy(C, D, A),
    iloczyn_w4 = iloczyn_wektorowy(C, D, B);


    if(iloczyn_w1 * iloczyn_w2 < 0 && iloczyn_w3 * iloczyn_w4 < 0) return 1;

    if(punkt_na_odcinku(A, B, C, iloczyn_w1)) return 1;
    if(punkt_na_odcinku(A, B, D, iloczyn_w2)) return 1;
    if(punkt_na_odcinku(C, D, A, iloczyn_w3)) return 1;
    if(punkt_na_odcinku(C, D, B, iloczyn_w4)) return 1;

    return 0;
}

int main(int argc, char** argv) {
    punkt A, B, C, D;

    std::cout << "Podaj x i y punktu A: ";
    std::cin >> A.x >> A.y;
    
    std::cout << "Podaj x i y punktu B: ";
    std::cin >> B.x >> B.y;

    std::cout << "Podaj x i y punktu C: ";
    std::cin >> C.x >> C.y;

    std::cout << "Podaj x i y punktu D: ";
    std::cin >> D.x >> D.y;
    
    przecinaja(A, B, C, D) ? std::cout << "Tak\n" : std::cout << "Nie\n";
    
    return 0;
}
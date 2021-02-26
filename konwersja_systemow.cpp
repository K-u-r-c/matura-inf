//Zamiana z systemu dziesietnego na jakikolwiek mniejszy od 17-tkowego

#include <iostream>

using namespace std;

void konwerter(int liczba, int podstawa) {
    int wyniki[30], i = 0;

    cout << "base " << podstawa << ": ";
    
    while(liczba) {
        wyniki[i++] = liczba % podstawa;
        liczba /= podstawa;
    }
    
    for(int j = i - 1; j >= 0; j--) {
        switch(wyniki[j]) {
            case 10:
                cout << 'A';
                break;
            case 11:
                cout << 'B';
                break;
            case 12:
                cout << 'C';
                break;
            case 13:
                cout << 'D';
                break;
            case 14:
                cout << 'E';
                break;
            case 15:
                cout << 'F';
                break;
            default:
                cout << wyniki[j];
                break;
        }
    }

    cout << endl;
}

int main(int argc, char** argv) {
    int liczba = 0, podstawa = 0;

    cout << "Podaj liczbe: ";
    cin >> liczba;
    cout << "Podaj podstawe: ";
    cin >> podstawa;

    konwerter(liczba, podstawa);

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int S;
    double FA;

    cout << "Sonidos por minuto: ";
    cin >> S;

    FA = S / 4.0 + 40;

    cout << "Temperatura: " << FA << " grados Fahrenheit";
    return 0;
}

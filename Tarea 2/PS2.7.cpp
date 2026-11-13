#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Y;
    double F;

    cout << "Ingrese Y: ";
    cin >> Y;

    switch (Y % 4) {
        case 0:
            F = pow(Y, 3);
            break;
        case 1:
            F = (pow(Y, 2) - 14) / pow(Y, 3);
            break;
        case 2:
            F = pow(Y, 3) + 5;
            break;
        case 3:
            F = sqrt(Y);
            break;
    }

    cout << "Resultado: " << F;
    return 0;
}

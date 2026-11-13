#include <iostream>
using namespace std;

int main() {
    double N1, N2, N3, MAYOR;

    cout << "Ingrese tres numeros: ";
    cin >> N1 >> N2 >> N3;

    MAYOR = N1;

    if (N2 > MAYOR)
        MAYOR = N2;

    if (N3 > MAYOR)
        MAYOR = N3;

    cout << "El mayor es: " << MAYOR;
    return 0;
}

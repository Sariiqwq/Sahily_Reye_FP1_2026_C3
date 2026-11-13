#include <iostream>
using namespace std;

int main() {
    int MED;
    double VAL;

    cout << "1. Pulgadas a milimetros\n";
    cout << "2. Yardas a metros\n";
    cout << "3. Millas a kilometros\n";
    cout << "Seleccione: ";
    cin >> MED;

    cout << "Ingrese el valor: ";
    cin >> VAL;

    switch (MED) {
        case 1:
            cout << VAL * 25.40 << " milimetros";
            break;
        case 2:
            cout << VAL * 0.9144 << " metros";
            break;
        case 3:
            cout << VAL * 1.6093 << " kilometros";
            break;
        default:
            cout << "Opcion incorrecta";
    }

    return 0;
}

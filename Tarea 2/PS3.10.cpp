#include <iostream>
using namespace std;

int main() {
    double L[6], TOTAL = 0;
    int BOLETOS[6] = {};

    for (int i = 0; i < 6; i++) {
        cout << "Precio de localidad " << i + 1 << ": ";
        cin >> L[i];
    }

    int CLA, CAN;

    cout << "Ingrese localidad y cantidad (0 0 para terminar): ";
    cin >> CLA >> CAN;

    while (CLA != 0 || CAN != 0) {
        if (CLA >= 1 && CLA <= 6 && CAN >= 0) {
            double VENTA = L[CLA - 1] * CAN;
            BOLETOS[CLA - 1] += CAN;
            TOTAL += VENTA;

            cout << "Monto de esta venta: " << VENTA << endl;
        } else {
            cout << "Datos incorrectos\n";
        }

        cout << "Ingrese localidad y cantidad (0 0 para terminar): ";
        cin >> CLA >> CAN;
    }

    for (int i = 0; i < 6; i++)
        cout << "Boletos localidad " << i + 1 << ": "
             << BOLETOS[i] << endl;

    cout << "Recaudacion total: " << TOTAL;

    return 0;
}

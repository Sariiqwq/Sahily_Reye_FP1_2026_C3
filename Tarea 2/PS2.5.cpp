#include <iostream>
using namespace std;

int main() {
    double COM, PAGO;

    cout << "Ingrese el monto de la compra: ";
    cin >> COM;

    if (COM < 800)
        PAGO = COM;
    else if (COM <= 1500)
        PAGO = COM * 0.90;
    else if (COM <= 5000)
        PAGO = COM * 0.85;
    else
        PAGO = COM * 0.80;

    cout << "Total a pagar: $" << PAGO;
    return 0;
}

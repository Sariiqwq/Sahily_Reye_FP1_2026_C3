#include <iostream>
using namespace std;

int main() {
    double SAL, PAGO, TARIFA = 0;
    int CAT, PHE;

    cout << "Ingrese el salario: ";
    cin >> SAL;

    cout << "Ingrese la categoria: ";
    cin >> CAT;

    cout << "Ingrese las horas extras: ";
    cin >> PHE;

    if (CAT == 1)
        TARIFA = 40;
    else if (CAT == 2)
        TARIFA = 50;
    else if (CAT == 3)
        TARIFA = 85;

    if (CAT >= 1 && CAT <= 3) {
        if (PHE > 30)
            PHE = 30;

        PAGO = SAL + PHE * TARIFA;
    } else {
        PAGO = SAL;
    }

    cout << "Pago total: $" << PAGO;
    return 0;
}

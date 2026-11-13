#include <iostream>
using namespace std;

int main() {
    double SAL, NUEVO;
    cout << "Ingrese el salario: ";
    cin >> SAL;

    if (SAL < 18000)
        NUEVO = SAL * 1.12;
    else if (SAL <= 30000)
        NUEVO = SAL * 1.08;
    else if (SAL <= 50000)
        NUEVO = SAL * 1.07;
    else
        NUEVO = SAL * 1.06;

    cout << "Nuevo salario: " << NUEVO;
    return 0;
}

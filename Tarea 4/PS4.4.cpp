#include <iostream>
#include <cmath>
using namespace std;

double calcularInversion(int meses, double capital, double tasa) {
    return capital * pow(1 + tasa / 100, meses);
}

int main() {
    int meses;
    double capital, tasa;

    cout << "Ingrese los meses: ";
    cin >> meses;
    cout << "Ingrese el capital: ";
    cin >> capital;
    cout << "Ingrese la tasa mensual (%): ";
    cin >> tasa;

    cout << "Capital final: "
         << calcularInversion(meses, capital, tasa);

    return 0;
}

#include <iostream>
using namespace std;

void calcularPromedios(int n) {
    int num, sumaP = 0, sumaI = 0, contP = 0, contI = 0;

    for (int i = 1; i <= n; i++) {
        cout << "Ingrese un numero: ";
        cin >> num;

        if (num % 2 == 0) {
            sumaP += num;
            contP++;
        } else {
            sumaI += num;
            contI++;
        }
    }

    if (contP > 0)
        cout << "Promedio de pares: " << (double)sumaP / contP << endl;
    else
        cout << "No hay numeros pares." << endl;

    if (contI > 0)
        cout << "Promedio de impares: " << (double)sumaI / contI << endl;
    else
        cout << "No hay numeros impares." << endl;
}

int main() {
    int n;
    cout << "Cantidad de numeros: ";
    cin >> n;

    calcularPromedios(n);
    return 0;
}

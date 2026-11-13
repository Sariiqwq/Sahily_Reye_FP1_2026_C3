#include <iostream>
using namespace std;

double calcularSerie(int n) {
    double resultado = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            resultado *= 1.0 / i;
        else
            resultado /= 1.0 / i;
    }

    return resultado;
}

int main() {
    int n;
    cout << "Ingrese N: ";
    cin >> n;

    cout << "Resultado: " << calcularSerie(n);
    return 0;
}

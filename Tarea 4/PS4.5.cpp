#include <iostream>
#include <cmath>
using namespace std;

long long calcularSerie(int n) {
    long long suma = 0;

    for (int i = 1; i <= n; i++) {
        long long termino = pow(i, i);

        if (i % 2 == 0)
            suma -= termino;
        else
            suma += termino;
    }

    return suma;
}

int main() {
    int n;
    cout << "Ingrese N: ";
    cin >> n;

    cout << "Resultado: " << calcularSerie(n);
    return 0;
}

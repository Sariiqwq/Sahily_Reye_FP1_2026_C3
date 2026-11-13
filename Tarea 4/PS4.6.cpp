#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

double calcularCoseno(double x, int &terminos) {
    double suma = 1, termino;
    int k = 1;

    do {
        termino = pow(x, 2 * k) / factorial(2 * k);

        if (k % 2 == 1)
            termino = -termino;

        suma += termino;
        k++;
    } while (fabs(termino) > 0.001);

    terminos = k - 1;
    return suma;
}

int main() {
    double x;
    int terminos;

    cout << "Ingrese X: ";
    cin >> x;

    cout << "Coseno aproximado: "
         << calcularCoseno(x, terminos) << endl;
    cout << "Numero de terminos: " << terminos;

    return 0;
}

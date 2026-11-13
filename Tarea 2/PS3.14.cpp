#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double X, TERMINO, SUMA = 0;
    int I = 0, CONT = 0;

    cout << "Ingrese X en radianes: ";
    cin >> X;

    do {
        TERMINO = pow(-1, I) * pow(X, 2 * I + 1);
        double FACT = 1;

        for (int j = 1; j <= 2 * I + 1; j++)
            FACT *= j;

        TERMINO /= FACT;
        SUMA += TERMINO;

        CONT++;
        I++;

    } while (fabs(TERMINO) > 0.001);

    cout << "Seno aproximado: " << SUMA << endl;
    cout << "Numero de terminos: " << CONT;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int N, NUM;
    int POS = 0, NEG = 0, CERO = 0;

    cout << "Cantidad de numeros: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "Ingrese un numero: ";
        cin >> NUM;

        if (NUM > 0)
            POS++;
        else if (NUM < 0)
            NEG++;
        else
            CERO++;
    }

    cout << "Positivos: " << POS << endl;
    cout << "Negativos: " << NEG << endl;
    cout << "Nulos: " << CERO;

    return 0;
}

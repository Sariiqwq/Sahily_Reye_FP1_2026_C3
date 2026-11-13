#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int LIM;

    cout << "Ingrese el limite de busqueda: ";
    cin >> LIM;

    for (int T = 1; T <= LIM; T++) {
        for (int P = 1; P <= LIM; P++) {
            for (int R = 1; R <= LIM; R++) {

                double RESULTADO =
                    7 * pow(T, 4) -
                    6 * pow(P, 3) +
                    12 * pow(R, 5);

                if (RESULTADO < 5850) {
                    cout << "T = " << T
                         << ", P = " << P
                         << ", R = " << R << endl;
                }
            }
        }
    }

    return 0;
}

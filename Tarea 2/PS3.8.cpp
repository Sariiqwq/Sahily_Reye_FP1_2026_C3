#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, Y;
    double F;

    cout << "Cantidad de valores: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "Ingrese Y: ";
        cin >> Y;

        if (Y >= 0 && Y <= 15)
            F = pow(Y, 2) + 15;
        else if (Y > 15 && Y <= 30)
            F = pow(Y, 3) - pow(Y, 2) + 12;
        else if (Y > 30 && Y <= 60)
            F = 4 * pow(Y, 3) / pow(Y, 2) + 8;
        else
            F = 0;

        cout << "F(" << Y << ") = " << F << endl;
    }

    return 0;
}

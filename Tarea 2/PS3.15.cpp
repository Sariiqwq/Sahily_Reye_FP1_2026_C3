#include <iostream>
using namespace std;

int main() {
    int N1, N2, AUX;

    cout << "Ingrese dos numeros: ";
    cin >> N1 >> N2;

    while (N2 != 0) {
        AUX = N2;
        N2 = N1 % N2;
        N1 = AUX;
    }

    cout << "MCD: " << N1;
    return 0;
}

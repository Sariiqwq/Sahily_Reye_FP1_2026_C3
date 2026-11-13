#include <iostream>
using namespace std;

bool esPrimo(int N) {
    if (N < 2) return false;

    for (int i = 2; i * i <= N; i++)
        if (N % i == 0)
            return false;

    return true;
}

int main() {
    int N1, N2;

    cout << "Ingrese dos numeros: ";
    cin >> N1 >> N2;

    if (N1 > N2) {
        int AUX = N1;
        N1 = N2;
        N2 = AUX;
    }

    for (int i = N1; i + 2 <= N2; i++) {
        if (esPrimo(i) && esPrimo(i + 2))
            cout << i << " y " << i + 2 << endl;
    }

    return 0;
}

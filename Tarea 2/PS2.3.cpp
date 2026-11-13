#include <iostream>
using namespace std;

int main() {
    int N1, N2;

    cout << "Ingrese dos numeros: ";
    cin >> N1 >> N2;

    if (N2 != 0 && N1 % N2 == 0)
        cout << N2 << " es divisor de " << N1;
    else
        cout << N2 << " no es divisor de " << N1;

    return 0;
}

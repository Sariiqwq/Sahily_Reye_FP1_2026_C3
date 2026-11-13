#include <iostream>
using namespace std;

bool esPerfecto(int n) {
    int suma = 0;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            suma += i;
    }

    return suma == n;
}

int main() {
    int n;
    cout << "Ingrese N: ";
    cin >> n;

    cout << "Numeros perfectos: ";

    for (int i = 1; i <= n; i++) {
        if (esPerfecto(i))
            cout << i << " ";
    }

    return 0;
}

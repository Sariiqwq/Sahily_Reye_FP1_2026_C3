#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    long long SUMA = 0;

    cout << "Ingrese N: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1)
            SUMA += pow(i, i);
        else
            SUMA -= pow(i, i);
    }

    cout << "Resultado: " << SUMA;
    return 0;
}

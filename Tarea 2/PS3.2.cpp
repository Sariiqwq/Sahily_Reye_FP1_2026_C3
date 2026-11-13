#include <iostream>
using namespace std;

int main() {
    int N;
    double SUMA = 0;

    cout << "Ingrese N: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
        SUMA += 1.0 / i;

    cout << "Resultado: " << SUMA;
    return 0;
}

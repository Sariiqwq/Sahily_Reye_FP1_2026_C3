#include <iostream>
using namespace std;

int main() {
    int N;
    double PRODUCTO = 1;

    cout << "Ingrese N: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
        PRODUCTO *= 1.0 / i;

    cout << "Resultado: " << PRODUCTO;
    return 0;
}

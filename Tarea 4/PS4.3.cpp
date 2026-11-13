#include <iostream>
using namespace std;

long long factorial(int n) {
    long long resultado = 1;

    for (int i = 1; i <= n; i++)
        resultado *= i;

    return resultado;
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "Factorial: " << factorial(n);
    return 0;
}

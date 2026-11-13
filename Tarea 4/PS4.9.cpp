#include <iostream>
using namespace std;

void invertirNumero(int n) {
    while (n > 0) {
        cout << n % 10 << " ";
        n /= 10;
    }
}

int main() {
    int n;
    cout << "Ingrese un numero de cuatro digitos: ";
    cin >> n;

    invertirNumero(n);
    return 0;
}

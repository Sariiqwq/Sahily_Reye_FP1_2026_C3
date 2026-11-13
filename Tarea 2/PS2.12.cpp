#include <iostream>
using namespace std;

int main() {
    int NUM, D1, D2, D3, D4;

    cout << "Ingrese un numero de cuatro digitos: ";
    cin >> NUM;

    D1 = NUM / 1000;
    D2 = (NUM / 100) % 10;
    D3 = (NUM / 10) % 10;
    D4 = NUM % 10;

    if (NUM >= 1000 && NUM <= 9999 &&
        D1 % 2 == 0 && D2 % 2 == 0 &&
        D3 % 2 == 0 && D4 % 2 == 0)
        cout << "Todos los digitos son pares";
    else
        cout << "No todos los digitos son pares";

    return 0;
}

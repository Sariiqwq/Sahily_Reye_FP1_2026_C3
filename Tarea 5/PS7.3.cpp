#include <iostream>
#include <string>
using namespace std;

int main() {
    string cad;

    cout << "Ingrese una cadena: ";
    getline(cin, cad);

    while (cad.length() < 30)
        cad += '-';

    cout << "Cadena modificada: " << cad;

    return 0;
}

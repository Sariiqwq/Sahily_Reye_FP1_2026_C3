#include <iostream>
#include <string>
using namespace std;

int main() {
    string telefono;

    cout << "Ingrese el numero telefonico: ";
    cin >> telefono;

    if (telefono.length() == 10) {
        cout << "Nueva cadena: ("
             << telefono.substr(0, 2) << ")-"
             << telefono[2] << "-"
             << telefono.substr(3);
    }
    else {
        cout << "El numero debe tener 10 digitos";
    }

    return 0;
}

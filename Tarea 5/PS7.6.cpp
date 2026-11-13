#include <iostream>
#include <string>
using namespace std;

int main() {
    string cad, mayor = "";
    char respuesta;

    do {
        cout << "Desea ingresar una cadena (S/N)? ";
        cin >> respuesta;
        cin.ignore(10000, '\n');

        if (respuesta == 'S' || respuesta == 's') {
            cout << "Ingrese una cadena: ";
            getline(cin, cad);

            if (cad.length() > mayor.length())
                mayor = cad;
        }

    } while (respuesta == 'S' || respuesta == 's');

    if (mayor != "")
        cout << "Cadena de mayor longitud: " << mayor;

    return 0;
}

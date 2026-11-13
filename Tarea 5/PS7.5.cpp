#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string cad;

    cout << "Ingrese una cadena: ";
    getline(cin, cad);

    bool inicio = true;

    for (int i = 0; i < cad.length(); i++) {
        if (inicio && isalpha((unsigned char)cad[i]))
            cad[i] = toupper((unsigned char)cad[i]);

        inicio = (cad[i] == ' ');
    }

    cout << "Resultado: " << cad;

    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string ARC[10];
    int maximo = -1;
    int posicion = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese la cadena " << i + 1 << ": ";
        getline(cin, ARC[i]);
    }

    for (int i = 0; i < 10; i++) {
        int mayusculas = 0;

        for (int j = 0; j < ARC[i].length(); j++) {
            if (isupper((unsigned char)ARC[i][j]))
                mayusculas++;
        }

        if (mayusculas > maximo) {
            maximo = mayusculas;
            posicion = i;
        }
    }

    cout << "\nCadena con mas mayusculas: " << ARC[posicion];

    return 0;
}

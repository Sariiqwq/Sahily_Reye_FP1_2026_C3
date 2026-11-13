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
        int vocales = 0;

        for (int j = 0; j < ARC[i].length(); j++) {
            char c = tolower((unsigned char)ARC[i][j]);

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u')
                vocales++;
        }

        if (vocales > maximo) {
            maximo = vocales;
            posicion = i;
        }
    }

    cout << "\nCadena con mas vocales: " << ARC[posicion];

    return 0;
}

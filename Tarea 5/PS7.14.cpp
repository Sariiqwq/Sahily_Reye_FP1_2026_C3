#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string ARC[20];
    int frecuencia[80] = {0};

    for (int i = 0; i < 20; i++) {
        cout << "Ingrese la cadena " << i + 1 << ": ";
        getline(cin, ARC[i]);
    }

    for (int i = 0; i < 20; i++) {
        stringstream ss(ARC[i]);
        string palabra;

        while (ss >> palabra) {
            int longitud = palabra.length();

            if (longitud < 80)
                frecuencia[longitud]++;
        }
    }

    cout << "\nLongitud de la palabra    Frecuencia\n";

    for (int i = 1; i < 80; i++) {
        if (frecuencia[i] > 0) {
            cout << i << "                         "
                 << frecuencia[i] << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string ARC[10];

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese la cadena " << i + 1 << ": ";
        getline(cin, ARC[i]);
    }

    for (int i = 0; i < 10; i++) {
        stringstream ss(ARC[i]);
        string palabra;
        int contador = 0;

        while (ss >> palabra)
            contador++;

        cout << "\nCadena " << i + 1
             << " tiene " << contador << " palabras";
    }

    return 0;
}

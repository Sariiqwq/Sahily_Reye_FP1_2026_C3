#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string cad1, cad2, palabra1, palabra2;
    stringstream s1, s2;

    cout << "Ingrese la primera cadena: ";
    getline(cin, cad1);

    cout << "Ingrese la segunda cadena: ";
    getline(cin, cad2);

    s1.str(cad1);
    s2.str(cad2);

    cout << "Resultado: ";

    while (true) {
        bool hay1 = bool(s1 >> palabra1);
        bool hay2 = bool(s2 >> palabra2);

        if (!hay1 && !hay2)
            break;

        if (hay1)
            cout << palabra1 << " ";

        if (hay2)
            cout << palabra2 << " ";
    }

    return 0;
}

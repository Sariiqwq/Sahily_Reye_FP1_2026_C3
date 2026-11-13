#include <iostream>
#include <string>
using namespace std;

int main() {
    string cad;

    cout << "Ingrese una cadena: ";
    getline(cin, cad);

    for (int i = 0; i < cad.length(); i++) {
        if ((i + 1) % 2 != 0)
            cout << cad[i];
    }

    return 0;
}

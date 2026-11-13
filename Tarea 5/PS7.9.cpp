#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string cad, palabra;
    vector<string> palabras;

    cout << "Ingrese una cadena: ";
    getline(cin, cad);

    stringstream ss(cad);

    while (ss >> palabra)
        palabras.push_back(palabra);

    cout << "Cadena inversa: ";

    for (int i = palabras.size() - 1; i >= 0; i--)
        cout << palabras[i] << " ";

    return 0;
}

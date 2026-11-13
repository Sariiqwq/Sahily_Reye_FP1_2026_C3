#include <iostream>
using namespace std;

int main() {
    int N1, N2, N3;

    cout << "Ingrese tres numeros diferentes: ";
    cin >> N1 >> N2 >> N3;

    if (N1 < N2 && N2 < N3)
        cout << "Estan en orden creciente";
    else
        cout << "No estan en orden creciente";

    return 0;
}


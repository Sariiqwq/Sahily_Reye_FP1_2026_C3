#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double L1, L2, L3, S, AREA;

    cout << "Ingrese los tres lados: ";
    cin >> L1 >> L2 >> L3;

    if (L1 + L2 > L3 && L1 + L3 > L2 && L2 + L3 > L1) {
        S = (L1 + L2 + L3) / 2;
        AREA = sqrt(S * (S - L1) * (S - L2) * (S - L3));

        cout << "Es un triangulo valido\n";
        cout << "Area: " << AREA << endl;

        if (L1 == L2 && L2 == L3)
            cout << "Equilatero";
        else if (L1 == L2 || L1 == L3 || L2 == L3)
            cout << "Isosceles";
        else
            cout << "Escaleno";
    } else {
        cout << "No forman un triangulo";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int N;
    double VIN[100][4] = {};
    double TIPO[4] = {};

    cout << "Ingrese la cantidad de anos: ";
    cin >> N;

    if (N < 1 || N > 100) return 0;

    for (int i = 0; i < N; i++) {
        cout << "\nAno " << i + 1 << endl;

        for (int j = 0; j < 4; j++) {
            cout << "Litros del tipo " << j + 1 << ": ";
            cin >> VIN[i][j];

            TIPO[j] += VIN[i][j];
        }
    }

    cout << "\nProduccion total por tipo:\n";
    for (int j = 0; j < 4; j++)
        cout << "Tipo " << j + 1 << ": " << TIPO[j] << endl;

    cout << "\nProduccion por ano:\n";
    for (int i = 0; i < N; i++) {
        double TOTAL = 0;

        for (int j = 0; j < 4; j++)
            TOTAL += VIN[i][j];

        cout << "Ano " << i + 1 << ": " << TOTAL << endl;
    }

    return 0;
}

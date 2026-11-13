#include <iostream>
using namespace std;

int main() {
    int N, EDAD, SEX;
    double PES, ALT;
    double PH = 0, PM = 0, AH = 0, AM = 0;
    int CH = 0, CM = 0;

    cout << "Cantidad de personas: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "Edad: ";
        cin >> EDAD;

        cout << "Peso: ";
        cin >> PES;

        cout << "Altura: ";
        cin >> ALT;

        cout << "Sexo (1 hombre, 0 mujer): ";
        cin >> SEX;

        if (EDAD >= 18) {
            if (SEX == 1) {
                PH += PES;
                AH += ALT;
                CH++;
            } else {
                PM += PES;
                AM += ALT;
                CM++;
            }
        }
    }

    if (CH > 0) {
        cout << "Peso promedio hombres: " << PH / CH << endl;
        cout << "Altura promedio hombres: " << AH / CH << endl;
    }

    if (CM > 0) {
        cout << "Peso promedio mujeres: " << PM / CM << endl;
        cout << "Altura promedio mujeres: " << AM / CM << endl;
    }

    return 0;
}

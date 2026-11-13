#include <iostream>
using namespace std;

int main() {
    string regiones[6] = {
        "NORTE", "CENTRO", "SUR",
        "GOLFO", "PACIFICO", "CARIBE"
    };

    string meses[12] = {
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    double T[6][12], PROM[6] = {};
    double MAYOR = -1e9, MENOR = 1e9;
    int RM = 0, MM = 0, Rm = 0, Mm = 0;

    for (int i = 0; i < 6; i++) {
        cout << "\nRegion " << regiones[i] << endl;

        for (int j = 0; j < 12; j++) {
            cout << meses[j] << ": ";
            cin >> T[i][j];

            PROM[i] += T[i][j];

            if (T[i][j] > MAYOR) {
                MAYOR = T[i][j];
                RM = i;
                MM = j;
            }

            if (T[i][j] < MENOR) {
                MENOR = T[i][j];
                Rm = i;
                Mm = j;
            }
        }

        PROM[i] /= 12;
    }

    cout << "\nPromedios anuales:\n";
    for (int i = 0; i < 6; i++)
        cout << regiones[i] << ": " << PROM[i] << endl;

    cout << "\nTemperatura mayor: " << MAYOR
         << " en " << regiones[RM] << ", " << meses[MM] << endl;

    cout << "Temperatura menor: " << MENOR
         << " en " << regiones[Rm] << ", " << meses[Mm] << endl;

    int mejor = 2;
    if (PROM[4] > PROM[mejor]) mejor = 4;
    if (PROM[5] > PROM[mejor]) mejor = 5;

    cout << "Mayor promedio entre SUR, PACIFICO y CARIBE: "
         << regiones[mejor];

    return 0;
}

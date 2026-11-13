#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    string cad;
    string meses[12] = {
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    int dia, mes, anio;

    cout << "Ingrese la fecha (dd/mm/aa): ";
    getline(cin, cad);

    if (sscanf(cad.c_str(), "%d/%d/%d", &dia, &mes, &anio) == 3
        && mes >= 1 && mes <= 12) {

        cout << setfill('0') << setw(2) << dia
             << " de " << meses[mes - 1]
             << " de " << 2000 + anio;
    }
    else {
        cout << "Fecha incorrecta";
    }

    return 0;
}

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    string cad;
    char respuesta;

    time_t ahora = time(0);
    tm *hoy = localtime(&ahora);

    stringstream ss;

    ss << setfill('0')
       << setw(2) << hoy->tm_mday << "/"
       << setw(2) << hoy->tm_mon + 1 << "/"
       << setw(4) << hoy->tm_year + 1900;

    string fecha = ss.str();

    do {
        cout << "Desea ingresar una cadena (S/N)? ";
        cin >> respuesta;
        cin.ignore(10000, '\n');

        if (respuesta == 'S' || respuesta == 's') {
            cout << "Ingrese la cadena: ";
            getline(cin, cad);

            if (cad.substr(0, 10) == fecha)
                cout << cad << endl;
        }

    } while (respuesta == 'S' || respuesta == 's');

    return 0;
}

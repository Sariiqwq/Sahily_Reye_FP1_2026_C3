#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

struct Equipo {
    string nombre;
    int jugados = 0;
    int ganados = 0;
    int empatados = 0;
    int perdidos = 0;
    int golesFavor = 0;
    int golesContra = 0;
    int diferencia = 0;
    int puntos = 0;
};

int Buscar(Equipo e[], int n, string nombre) {
    for (int i = 0; i < n; i++)
        if (e[i].nombre == nombre)
            return i;
    return -1;
}

void Actualizar(Equipo &a, Equipo &b, int golesA, int golesB) {
    a.jugados++;
    b.jugados++;

    a.golesFavor += golesA;
    a.golesContra += golesB;
    b.golesFavor += golesB;
    b.golesContra += golesA;

    if (golesA > golesB) {
        a.ganados++;
        b.perdidos++;
        a.puntos += 3;
    } else if (golesA < golesB) {
        b.ganados++;
        a.perdidos++;
        b.puntos += 3;
    } else {
        a.empatados++;
        b.empatados++;
        a.puntos++;
        b.puntos++;
    }

    a.diferencia = a.golesFavor - a.golesContra;
    b.diferencia = b.golesFavor - b.golesContra;
}

void MostrarTabla(Equipo e[], int n) {
    sort(e, e + n, [](const Equipo &a, const Equipo &b) {
        if (a.puntos != b.puntos)
            return a.puntos > b.puntos;
        return a.diferencia > b.diferencia;
    });

    cout << "\n--- TABLA DE POSICIONES ---\n";
    cout << "Equipo | PJ | PG | PE | PP | GF | GC | DG | Puntos\n";

    for (int i = 0; i < n; i++) {
        cout << e[i].nombre << " | "
             << e[i].jugados << " | "
             << e[i].ganados << " | "
             << e[i].empatados << " | "
             << e[i].perdidos << " | "
             << e[i].golesFavor << " | "
             << e[i].golesContra << " | "
             << e[i].diferencia << " | "
             << e[i].puntos << '\n';
    }
}

int main() {
    Equipo FUTBOL[20];
    int n;

    do {
        cout << "Cantidad de equipos (1-20): ";
        cin >> n;
    } while (n < 1 || n > 20);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        cout << "Nombre del equipo " << i + 1 << ": ";
        getline(cin, FUTBOL[i].nombre);
    }

    cout << "\nRegistra los partidos de la fecha.\n";

    while (true) {
        string local, visitante;
        int golesLocal, golesVisitante;

        cout << "\nEquipo local (FIN para terminar): ";
        getline(cin, local);

        if (local == "FIN")
            break;

        cout << "Goles del equipo local: ";
        cin >> golesLocal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Equipo visitante: ";
        getline(cin, visitante);

        cout << "Goles del equipo visitante: ";
        cin >> golesVisitante;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int posLocal = Buscar(FUTBOL, n, local);
        int posVisitante = Buscar(FUTBOL, n, visitante);

        if (posLocal == -1 || posVisitante == -1) {
            cout << "Uno de los equipos no existe.\n";
        } else if (posLocal == posVisitante) {
            cout << "Un equipo no puede jugar contra si mismo.\n";
        } else if (golesLocal < 0 || golesVisitante < 0) {
            cout << "Los goles no pueden ser negativos.\n";
        } else {
            Actualizar(FUTBOL[posLocal], FUTBOL[posVisitante],
                       golesLocal, golesVisitante);
        }
    }

    MostrarTabla(FUTBOL, n);

    return 0;
}

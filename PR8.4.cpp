
#include <iostream>
#include <string>
using namespace std;

struct Ubicacion {
    string zona;
    string calle;
    string colonia;
};

struct Propiedad {
    string clave;
    float superficieCubierta;
    float superficieTerreno;
    string caracteristicas;
    Ubicacion ubi;
    float precio;
    char disponibilidad;
};

void Lectura(Propiedad A[], int T) {
    for (int i = 0; i < T; i++) {
        cout << "\n--- PROPIEDAD " << i + 1 << " ---\n";

        cout << "Clave: ";
        getline(cin >> ws, A[i].clave);

        cout << "Superficie cubierta: ";
        cin >> A[i].superficieCubierta;

        cout << "Superficie terreno: ";
        cin >> A[i].superficieTerreno;

        cout << "Caracteristicas: ";
        getline(cin >> ws, A[i].caracteristicas);

        cout << "Zona: ";
        getline(cin, A[i].ubi.zona);

        cout << "Calle: ";
        getline(cin, A[i].ubi.calle);

        cout << "Colonia: ";
        getline(cin, A[i].ubi.colonia);

        cout << "Precio: ";
        cin >> A[i].precio;

        cout << "Disponibilidad (V = Venta, R = Renta): ";
        cin >> A[i].disponibilidad;

        if (A[i].disponibilidad >= 'a' &&
            A[i].disponibilidad <= 'z') {
            A[i].disponibilidad -= 32;
        }
    }
}

void Mostrar(Propiedad P) {
    cout << "\nClave: " << P.clave;
    cout << "\nSuperficie cubierta: " << P.superficieCubierta;
    cout << "\nSuperficie terreno: " << P.superficieTerreno;
    cout << "\nCaracteristicas: " << P.caracteristicas;
    cout << "\nCalle: " << P.ubi.calle;
    cout << "\nColonia: " << P.ubi.colonia;
    cout << "\nPrecio: " << P.precio << endl;
}

void F1(Propiedad A[], int T) {
    cout << "\n--- PROPIEDADES PARA VENTA EN MIRAFLORES ---\n";

    bool encontrado = false;

    for (int i = 0; i < T; i++) {
        if (A[i].disponibilidad == 'V' &&
            A[i].ubi.zona == "Miraflores" &&
            A[i].precio >= 450000 &&
            A[i].precio <= 650000) {

            Mostrar(A[i]);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron propiedades.\n";
}

void F2(Propiedad A[], int T) {
    string zona;
    float limiteInferior, limiteSuperior;

    cout << "\n--- PROPIEDADES PARA RENTA ---\n";

    cout << "Ingrese la zona geografica: ";
    getline(cin >> ws, zona);

    cout << "Limite inferior del precio: ";
    cin >> limiteInferior;

    cout << "Limite superior del precio: ";
    cin >> limiteSuperior;

    bool encontrado = false;

    for (int i = 0; i < T; i++) {
        if (A[i].disponibilidad == 'R' &&
            A[i].ubi.zona == zona &&
            A[i].precio >= limiteInferior &&
            A[i].precio <= limiteSuperior) {

            Mostrar(A[i]);
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontraron propiedades.\n";
}

int main() {
    Propiedad PROPIE[100];
    int TAM;

    do {
        cout << "Cantidad de propiedades: ";
        cin >> TAM;
    } while (TAM < 1 || TAM > 100);

    Lectura(PROPIE, TAM);

    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}


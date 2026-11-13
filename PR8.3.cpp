
#include <iostream>
#include <string>
using namespace std;

struct Domicilio {
    string calle;
    int numero;
    string colonia;
    string codigoPostal;
    string ciudad;
};

struct Paciente {
    string nombre;
    int edad;
    char sexo;
    int condicion;
    Domicilio dom;
    string telefono;
};

void Lectura(Paciente A[], int T) {
    for (int i = 0; i < T; i++) {
        cout << "\n--- PACIENTE " << i + 1 << " ---\n";

        cout << "Nombre: ";
        getline(cin >> ws, A[i].nombre);

        cout << "Edad: ";
        cin >> A[i].edad;

        cout << "Sexo (F/M): ";
        cin >> A[i].sexo;

        if (A[i].sexo >= 'a' && A[i].sexo <= 'z')
            A[i].sexo -= 32;

        do {
            cout << "Condicion (1-5): ";
            cin >> A[i].condicion;
        } while (A[i].condicion < 1 || A[i].condicion > 5);

        cout << "Calle: ";
        getline(cin >> ws, A[i].dom.calle);

        cout << "Numero: ";
        cin >> A[i].dom.numero;

        cout << "Colonia: ";
        getline(cin >> ws, A[i].dom.colonia);

        cout << "Codigo postal: ";
        getline(cin, A[i].dom.codigoPostal);

        cout << "Ciudad: ";
        getline(cin, A[i].dom.ciudad);

        cout << "Telefono: ";
        getline(cin, A[i].telefono);
    }
}

void F1(Paciente A[], int T) {
    int hombres = 0, mujeres = 0;

    for (int i = 0; i < T; i++) {
        if (A[i].sexo == 'M')
            hombres++;
        else if (A[i].sexo == 'F')
            mujeres++;
    }

    cout << "\n--- PORCENTAJES ---\n";
    cout << "Hombres: " << (float)hombres / T * 100 << "%\n";
    cout << "Mujeres: " << (float)mujeres / T * 100 << "%\n";
}

void F2(Paciente A[], int T) {
    int categorias[5] = {0};

    for (int i = 0; i < T; i++) {
        categorias[A[i].condicion - 1]++;
    }

    cout << "\n--- PACIENTES POR CONDICION ---\n";

    for (int i = 0; i < 5; i++) {
        cout << "Condicion " << i + 1 << ": "
             << categorias[i] << " pacientes\n";
    }
}

void F3(Paciente A[], int T) {
    cout << "\n--- PACIENTES EN CONDICION DE GRAVEDAD 5 ---\n";

    for (int i = 0; i < T; i++) {
        if (A[i].condicion == 5) {
            cout << "Nombre: " << A[i].nombre << endl;
            cout << "Telefono: " << A[i].telefono << endl;
        }
    }
}

int main() {
    Paciente HOSPITAL[100];
    int TAM;

    do {
        cout << "Cantidad de pacientes: ";
        cin >> TAM;
    } while (TAM < 1 || TAM > 100);

    Lectura(HOSPITAL, TAM);

    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

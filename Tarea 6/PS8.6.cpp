#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Domicilio {
    string calleNumero;
    int codigoPostal;
    string colonia;
    string ciudad;
    string telefono;
};

struct Calificacion {
    string materia;
    float promedio;
};

struct NivelEstudios {
    string nivel;
    int grado;
    string salon;
    Calificacion calificaciones[7];
};

struct Alumno {
    int matricula;
    string nombre;
    Domicilio domicilio;
    NivelEstudios estudios;
};

float Promedio(Alumno a) {
    float suma = 0;

    for (int i = 0; i < 7; i++)
        suma += a.estudios.calificaciones[i].promedio;

    return suma / 7;
}

void Lectura(Alumno escuela[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- ALUMNO " << i + 1 << " ---\n";

        cout << "Matricula: ";
        cin >> escuela[i].matricula;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nombre y apellido: ";
        getline(cin, escuela[i].nombre);

        cout << "Calle y numero: ";
        getline(cin, escuela[i].domicilio.calleNumero);

        cout << "Codigo postal: ";
        cin >> escuela[i].domicilio.codigoPostal;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Colonia: ";
        getline(cin, escuela[i].domicilio.colonia);

        cout << "Ciudad: ";
        getline(cin, escuela[i].domicilio.ciudad);

        cout << "Telefono: ";
        getline(cin, escuela[i].domicilio.telefono);

        cout << "Nivel (primaria, secundaria o preparatoria): ";
        getline(cin, escuela[i].estudios.nivel);

        cout << "Grado: ";
        cin >> escuela[i].estudios.grado;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Salon: ";
        getline(cin, escuela[i].estudios.salon);

        for (int j = 0; j < 7; j++) {
            cout << "\nMateria " << j + 1 << ": ";
            getline(cin, escuela[i].estudios.calificaciones[j].materia);

            cout << "Promedio: ";
            cin >> escuela[i].estudios.calificaciones[j].promedio;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void F1(Alumno escuela[], int n) {
    int matricula;

    cout << "\nMatricula del alumno: ";
    cin >> matricula;

    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        if (escuela[i].matricula == matricula) {
            cout << "Nombre: " << escuela[i].nombre
                 << "\nPromedio general: " << Promedio(escuela[i]) << '\n';

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Alumno no encontrado.\n";
}

void F2(Alumno escuela[], int n) {
    string nivel, salon;
    int grado;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nNivel: ";
    getline(cin, nivel);

    cout << "Grado: ";
    cin >> grado;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Salon: ";
    getline(cin, salon);

    cout << "\n--- ALUMNOS ENCONTRADOS ---\n";

    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        if (escuela[i].estudios.nivel == nivel &&
            escuela[i].estudios.grado == grado &&
            escuela[i].estudios.salon == salon) {

            cout << "\nMatricula: " << escuela[i].matricula
                 << "\nNombre: " << escuela[i].nombre
                 << "\nPromedio: " << Promedio(escuela[i]) << '\n';

            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No hay alumnos que coincidan.\n";
}

void F3(Alumno escuela[], int n) {
    string nivel, salon;
    int grado;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nNivel: ";
    getline(cin, nivel);

    cout << "Grado: ";
    cin >> grado;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Salon: ";
    getline(cin, salon);

    int posicion = -1;
    float mayor = -1;

    for (int i = 0; i < n; i++) {
        if (escuela[i].estudios.nivel == nivel &&
            escuela[i].estudios.grado == grado &&
            escuela[i].estudios.salon == salon) {

            float promedio = Promedio(escuela[i]);

            if (promedio > mayor) {
                mayor = promedio;
                posicion = i;
            }
        }
    }

    cout << "\n--- ALUMNO CON MAYOR PROMEDIO ---\n";

    if (posicion != -1) {
        cout << "Matricula: " << escuela[posicion].matricula
             << "\nNombre: " << escuela[posicion].nombre
             << "\nPromedio: " << mayor << '\n';
    } else {
        cout << "No hay alumnos que coincidan.\n";
    }
}

int main() {
    Alumno ESCUELA[1000];
    int n, opcion;

    do {
        cout << "Cantidad de alumnos (1-1000): ";
        cin >> n;
    } while (n < 1 || n > 1000);

    Lectura(ESCUELA, n);

    do {
        cout << "\n===== ESCUELA =====\n"
             << "1. Buscar promedio por matricula\n"
             << "2. Listar alumnos por nivel, grado y salon\n"
             << "3. Buscar alumno con mayor promedio\n"
             << "0. Salir\n"
             << "Opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                F1(ESCUELA, n);
                break;

            case 2:
                F2(ESCUELA, n);
                break;

            case 3:
                F3(ESCUELA, n);
                break;

            case 0:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 0);

    return 0;
}

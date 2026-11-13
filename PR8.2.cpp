
#include <iostream>
#include <string>
using namespace std;

struct MatPro {
    string materia;
    float promedio;
};

struct Alumno {
    int matricula;
    string nombre;
    MatPro cal[5];
};

int main() {
    Alumno ALU[50];
    int N;

    do {
        cout << "Cantidad de alumnos: ";
        cin >> N;
    } while (N < 1 || N > 50);

    for (int i = 0; i < N; i++) {
        cout << "\nAlumno " << i + 1 << endl;

        cout << "Matricula: ";
        cin >> ALU[i].matricula;

        cout << "Nombre: ";
        cin.ignore();
        getline(cin, ALU[i].nombre);

        for (int j = 0; j < 5; j++) {
            cout << "\nMateria " << j + 1 << ": ";
            getline(cin, ALU[i].cal[j].materia);

            cout << "Promedio: ";
            cin >> ALU[i].cal[j].promedio;
            cin.ignore();
        }
    }

    float sumaCuarta = 0;

    cout << "\n--- PROMEDIO GENERAL DE CADA ALUMNO ---\n";

    for (int i = 0; i < N; i++) {
        float suma = 0;

        for (int j = 0; j < 5; j++) {
            suma += ALU[i].cal[j].promedio;
        }

        cout << "Matricula: " << ALU[i].matricula;
        cout << " | Promedio general: " << suma / 5 << endl;

        sumaCuarta += ALU[i].cal[3].promedio;
    }

    cout << "\n--- ALUMNOS CON MAS DE 9 EN LA TERCERA MATERIA ---\n";

    for (int i = 0; i < N; i++) {
        if (ALU[i].cal[2].promedio > 9) {
            cout << "Matricula: " << ALU[i].matricula << endl;
        }
    }

    cout << "\nPromedio general de la cuarta materia: "
         << sumaCuarta / N << endl;

    return 0;
}

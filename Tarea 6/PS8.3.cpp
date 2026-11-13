#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Profesor {
    int numero;
    string nombre;
    string departamento;
    string puesto;
    string grado;
    string nacionalidad;
    float salario[12];
};

float TotalAnual(Profesor p) {
    float total = 0;

    for (int i = 0; i < 12; i++)
        total += p.salario[i];

    return total;
}

void Lectura(Profesor p[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- PROFESOR " << i + 1 << " ---\n";

        cout << "Numero de empleado: ";
        cin >> p[i].numero;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nombre: ";
        getline(cin, p[i].nombre);
        cout << "Departamento: ";
        getline(cin, p[i].departamento);
        cout << "Puesto: ";
        getline(cin, p[i].puesto);
        cout << "Grado academico: ";
        getline(cin, p[i].grado);
        cout << "Nacionalidad: ";
        getline(cin, p[i].nacionalidad);

        for (int j = 0; j < 12; j++) {
            cout << "Salario del mes " << j + 1 << ": ";
            cin >> p[i].salario[j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void F1(Profesor p[], int n) {
    int mayor = 0;

    for (int i = 1; i < n; i++)
        if (TotalAnual(p[i]) > TotalAnual(p[mayor]))
            mayor = i;

    cout << "\n--- PROFESOR QUE MAS GANO ---\n";
    cout << "Nombre: " << p[mayor].nombre
         << "\nDepartamento: " << p[mayor].departamento
         << "\nNacionalidad: " << p[mayor].nacionalidad
         << "\nIngreso anual: $" << TotalAnual(p[mayor]) << '\n';
}

void F2(Profesor p[], int n) {
    float totalUniversidad = 0;
    float totalExtranjeros = 0;

    for (int i = 0; i < n; i++) {
        float total = TotalAnual(p[i]);
        totalUniversidad += total;

        if (p[i].nacionalidad != "Colombia")
            totalExtranjeros += total;
    }

    cout << "\n--- PAGOS A PROFESORES EXTRANJEROS ---\n";
    cout << "Total pagado a extranjeros: $" << totalExtranjeros << '\n';

    if (totalUniversidad > 0)
        cout << "Porcentaje del gasto total: "
             << (totalExtranjeros / totalUniversidad) * 100 << "%\n";
    else
        cout << "No hay salarios registrados.\n";
}

void F3(Profesor p[], int n) {
    string departamentos[4] = {
        "Economia", "Derecho", "Computacion", "Administracion"
    };

    float gastos[4] = {0, 0, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (p[i].departamento == departamentos[j])
                gastos[j] += TotalAnual(p[i]);
        }
    }

    int mayor = 0;

    for (int i = 1; i < 4; i++)
        if (gastos[i] > gastos[mayor])
            mayor = i;

    cout << "\n--- DEPARTAMENTO CON MAYOR GASTO ---\n";
    cout << "Departamento: " << departamentos[mayor]
         << "\nGasto anual: $" << gastos[mayor] << '\n';
}

int main() {
    Profesor EMPLE[200];
    int n;

    do {
        cout << "Cantidad de profesores (1-200): ";
        cin >> n;
    } while (n < 1 || n > 200);

    Lectura(EMPLE, n);

    F1(EMPLE, n);
    F2(EMPLE, n);
    F3(EMPLE, n);

    return 0;
}

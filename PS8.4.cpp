#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Domicilio {
    string calleNumero;
    string colonia;
    string codigoPostal;
    string ciudad;
    string telefono;
};

struct Empleado {
    int numero;
    string nombre;
    string departamento;
    Domicilio domicilio;
    float salario;
};

int Buscar(Empleado e[], int n, int numero) {
    for (int i = 0; i < n; i++)
        if (e[i].numero == numero)
            return i;
    return -1;
}

void LeerEmpleado(Empleado &e) {
    cout << "Nombre y apellido: ";
    getline(cin, e.nombre);

    cout << "Departamento: ";
    getline(cin, e.departamento);

    cout << "Calle y numero: ";
    getline(cin, e.domicilio.calleNumero);

    cout << "Colonia: ";
    getline(cin, e.domicilio.colonia);

    cout << "Codigo postal: ";
    getline(cin, e.domicilio.codigoPostal);

    cout << "Ciudad: ";
    getline(cin, e.domicilio.ciudad);

    cout << "Telefono: ";
    getline(cin, e.domicilio.telefono);

    cout << "Salario mensual: ";
    cin >> e.salario;
}

void Alta(Empleado e[], int &n) {
    if (n == 100) {
        cout << "No hay espacio para mas empleados.\n";
        return;
    }

    int numero;
    cout << "Numero del empleado: ";
    cin >> numero;

    if (Buscar(e, n, numero) != -1) {
        cout << "Ese empleado ya existe.\n";
        return;
    }

    Empleado nuevo;
    nuevo.numero = numero;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    LeerEmpleado(nuevo);

    int i = n - 1;

    while (i >= 0 && e[i].numero > numero) {
        e[i + 1] = e[i];
        i--;
    }

    e[i + 1] = nuevo;
    n++;

    cout << "Empleado registrado correctamente.\n";
}

void Baja(Empleado e[], int &n) {
    int numero;

    cout << "Numero del empleado que desea eliminar: ";
    cin >> numero;

    int pos = Buscar(e, n, numero);

    if (pos == -1) {
        cout << "Empleado no encontrado.\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
        e[i] = e[i + 1];

    n--;

    cout << "Empleado eliminado correctamente.\n";
}

void Listado(Empleado e[], int n) {
    string departamento;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre del departamento: ";
    getline(cin, departamento);

    cout << "\n--- EMPLEADOS DEL DEPARTAMENTO ---\n";

    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        if (e[i].departamento == departamento) {
            cout << "Numero: " << e[i].numero
                 << "\nNombre: " << e[i].nombre
                 << "\nSalario: $" << e[i].salario << "\n\n";

            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No hay empleados en ese departamento.\n";
}

int main() {
    Empleado EMPLE[100];
    int n = 0;
    int opcion;

    do {
        cout << "\n===== EMPRESA =====\n"
             << "1. Alta de empleado\n"
             << "2. Baja de empleado\n"
             << "3. Listado por departamento\n"
             << "4. Mostrar todos los empleados\n"
             << "0. Salir\n"
             << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                Alta(EMPLE, n);
                break;

            case 2:
                Baja(EMPLE, n);
                break;

            case 3:
                Listado(EMPLE, n);
                break;

            case 4:
                for (int i = 0; i < n; i++)
                    cout << EMPLE[i].numero << " | "
                         << EMPLE[i].nombre << " | "
                         << EMPLE[i].departamento << " | $"
                         << EMPLE[i].salario << '\n';
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

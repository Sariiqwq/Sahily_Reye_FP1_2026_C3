
#include <iostream>
#include <string>
using namespace std;

struct Banco {
    char nombre[50];
    char cuenta[30];
};

union FormaPago {
    Banco cheque;
    Banco nomina;
    char ventanilla;
};

struct Domicilio {
    string calleNumero;
    string colonia;
    string codigoPostal;
    string ciudad;
};

struct Vendedor {
    int numero;
    string nombre;
    float ventas[12];
    Domicilio dom;
    float salario;
    FormaPago pago;
    int clave;
};

void Lectura(Vendedor A[], int T) {
    for (int i = 0; i < T; i++) {
        cout << "\n--- VENDEDOR " << i + 1 << " ---\n";

        cout << "Numero de vendedor: ";
        cin >> A[i].numero;

        cout << "Nombre: ";
        getline(cin >> ws, A[i].nombre);

        cout << "\nVentas de los 12 meses:\n";

        for (int j = 0; j < 12; j++) {
            cout << "Mes " << j + 1 << ": ";
            cin >> A[i].ventas[j];
        }

        cout << "\nDomicilio\n";

        cout << "Calle y numero: ";
        getline(cin >> ws, A[i].dom.calleNumero);

        cout << "Colonia: ";
        getline(cin, A[i].dom.colonia);

        cout << "Codigo postal: ";
        getline(cin, A[i].dom.codigoPostal);

        cout << "Ciudad: ";
        getline(cin, A[i].dom.ciudad);

        cout << "Salario mensual: ";
        cin >> A[i].salario;

        do {
            cout << "\nForma de pago:\n";
            cout << "1. Cuenta de cheques\n";
            cout << "2. Nomina\n";
            cout << "3. Ventanilla\n";
            cout << "Seleccione: ";
            cin >> A[i].clave;
        } while (A[i].clave < 1 || A[i].clave > 3);

        switch (A[i].clave) {
            case 1:
                cout << "Nombre del banco: ";
                cin >> ws;
                cin.getline(A[i].pago.cheque.nombre, 50);

                cout << "Numero de cuenta: ";
                cin.getline(A[i].pago.cheque.cuenta, 30);
                break;

            case 2:
                cout << "Nombre del banco: ";
                cin >> ws;
                cin.getline(A[i].pago.nomina.nombre, 50);

                cout << "Numero de cuenta: ";
                cin.getline(A[i].pago.nomina.cuenta, 30);
                break;

            case 3:
                A[i].pago.ventanilla = 'S';
                break;
        }
    }
}

float TotalVentas(Vendedor A) {
    float suma = 0;

    for (int i = 0; i < 12; i++) {
        suma += A.ventas[i];
    }

    return suma;
}

void F1(Vendedor A[], int T) {
    cout << "\n--- VENTAS TOTALES ANUALES ---\n";

    for (int i = 0; i < T; i++) {
        cout << "\nVendedor: " << A[i].numero;
        cout << "\nNombre: " << A[i].nombre;
        cout << "\nVentas totales: " << TotalVentas(A[i]) << endl;
    }
}

void F2(Vendedor A[], int T) {
    cout << "\n--- INCREMENTO DE SALARIO ---\n";

    for (int i = 0; i < T; i++) {
        float total = TotalVentas(A[i]);

        if (total > 1500000) {
            A[i].salario = A[i].salario * 1.05;

            cout << "\nVendedor: " << A[i].numero;
            cout << "\nVentas: " << total;
            cout << "\nNuevo salario: " << A[i].salario << endl;
        }
    }
}

void F3(Vendedor A[], int T) {
    cout << "\n--- VENDEDORES CON VENTAS MENORES A 300000 ---\n";

    for (int i = 0; i < T; i++) {
        float total = TotalVentas(A[i]);

        if (total < 300000) {
            cout << "\nNumero: " << A[i].numero;
            cout << "\nNombre: " << A[i].nombre;
            cout << "\nVentas: " << total << endl;
        }
    }
}

void F4(Vendedor A[], int T) {
    cout << "\n--- VENDEDORES CON CUENTA DE CHEQUES ---\n";

    for (int i = 0; i < T; i++) {
        if (A[i].clave == 1) {
            cout << "\nNumero de vendedor: " << A[i].numero;
            cout << "\nBanco: " << A[i].pago.cheque.nombre;
            cout << "\nCuenta: " << A[i].pago.cheque.cuenta << endl;
        }
    }
}

int main() {
    Vendedor VENDEDORES[100];
    int TAM;

    do {
        cout << "Cantidad de vendedores: ";
        cin >> TAM;
    } while (TAM < 1 || TAM > 100);

    Lectura(VENDEDORES, TAM);

    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    cout << "\nFIN DEL PROGRAMA\n";

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int clave;
    string nombre;
    float precio;
    int existencia;
};

void Lectura(Producto A[], int T) {
    for (int i = 0; i < T; i++) {
        cout << "\nProducto " << i + 1 << endl;

        cout << "Clave: ";
        cin >> A[i].clave;

        cout << "Nombre: ";
        cin.ignore();
        getline(cin, A[i].nombre);

        cout << "Precio: ";
        cin >> A[i].precio;

        cout << "Existencia: ";
        cin >> A[i].existencia;
    }
}

int Buscar(Producto A[], int T, int clave) {
    for (int i = 0; i < T; i++) {
        if (A[i].clave == clave)
            return i;
    }
    return -1;
}

void Ventas(Producto A[], int T) {
    int clave, cantidad;
    float total = 0;

    cout << "\n--- VENTAS ---\n";

    cout << "Clave del producto (0 para terminar): ";
    cin >> clave;

    while (clave != 0) {
        int pos = Buscar(A, T, clave);

        if (pos != -1) {
            cout << "Cantidad: ";
            cin >> cantidad;

            if (cantidad > 0 && cantidad <= A[pos].existencia) {
                total += cantidad * A[pos].precio;
                A[pos].existencia -= cantidad;
            } else {
                cout << "Cantidad no disponible.\n";
            }
        } else {
            cout << "Producto no encontrado.\n";
        }

        cout << "Clave del producto (0 para terminar): ";
        cin >> clave;
    }

    cout << "Total de la venta: " << total << endl;
}

void Reabastecimiento(Producto A[], int T) {
    int clave, cantidad;

    cout << "\n--- REABASTECIMIENTO ---\n";

    cout << "Clave del producto (0 para terminar): ";
    cin >> clave;

    while (clave != 0) {
        int pos = Buscar(A, T, clave);

        if (pos != -1) {
            cout << "Cantidad a agregar: ";
            cin >> cantidad;

            if (cantidad > 0)
                A[pos].existencia += cantidad;
            else
                cout << "Cantidad inválida.\n";
        } else {
            cout << "Producto no encontrado.\n";
        }

        cout << "Clave del producto (0 para terminar): ";
        cin >> clave;
    }
}

void NuevosProductos(Producto A[], int &T) {
    int clave;

    cout << "\n--- NUEVOS PRODUCTOS ---\n";
    cout << "Clave (0 para terminar): ";
    cin >> clave;

    while (clave != 0 && T < 100) {
        if (Buscar(A, T, clave) != -1) {
            cout << "Esa clave ya existe.\n";
        } else {
            Producto nuevo;
            nuevo.clave = clave;

            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nuevo.nombre);

            cout << "Precio: ";
            cin >> nuevo.precio;

            cout << "Existencia: ";
            cin >> nuevo.existencia;

            int i = T - 1;

            while (i >= 0 && A[i].clave > nuevo.clave) {
                A[i + 1] = A[i];
                i--;
            }

            A[i + 1] = nuevo;
            T++;
        }

        if (T < 100) {
            cout << "Clave (0 para terminar): ";
            cin >> clave;
        } else {
            cout << "Inventario lleno.\n";
            break;
        }
    }
}

void Inventario(Producto A[], int T) {
    cout << "\n--- INVENTARIO COMPLETO ---\n";

    for (int i = 0; i < T; i++) {
        cout << "\nClave: " << A[i].clave;
        cout << "\nNombre: " << A[i].nombre;
        cout << "\nPrecio: " << A[i].precio;
        cout << "\nExistencia: " << A[i].existencia << endl;
    }
}

int main() {
    Producto INV[100];
    int TAM, OPE;

    do {
        cout << "Numero de productos: ";
        cin >> TAM;
    } while (TAM < 1 || TAM > 100);

    Lectura(INV, TAM);

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Ventas";
        cout << "\n2. Reabastecimiento";
        cout << "\n3. Nuevos productos";
        cout << "\n4. Inventario";
        cout << "\n0. Salir";
        cout << "\nOpcion: ";
        cin >> OPE;

        switch (OPE) {
            case 1:
                Ventas(INV, TAM);
                break;
            case 2:
                Reabastecimiento(INV, TAM);
                break;
            case 3:
                NuevosProductos(INV, TAM);
                break;
            case 4:
                Inventario(INV, TAM);
                break;
            case 0:
                cout << "Programa terminado.\n";
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
    } while (OPE != 0);

    return 0;
}

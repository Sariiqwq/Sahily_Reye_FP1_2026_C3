#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Producto {
    int clave;
    string nombre;
    int existencia;
};

int Buscar(Producto tienda[], int n, int clave) {
    for (int i = 0; i < n; i++)
        if (tienda[i].clave == clave)
            return i;
    return -1;
}

void Lectura(Producto tienda[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << '\n';

        cout << "Clave: ";
        cin >> tienda[i].clave;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nombre: ";
        getline(cin, tienda[i].nombre);

        cout << "Existencia: ";
        cin >> tienda[i].existencia;
    }
}

void Transacciones(Producto tienda[], int n) {
    char operacion;
    int clave, cantidad;

    cout << "\nOperacion (C = compra, V = venta, 0 = terminar): ";
    cin >> operacion;

    while (operacion != '0') {
        cout << "Clave del producto: ";
        cin >> clave;

        cout << "Cantidad: ";
        cin >> cantidad;

        int pos = Buscar(tienda, n, clave);

        if (pos == -1) {
            cout << "Producto no encontrado.\n";
        } else if (cantidad <= 0) {
            cout << "Cantidad no valida.\n";
        } else if (operacion == 'C' || operacion == 'c') {
            tienda[pos].existencia += cantidad;
            cout << "Compra registrada.\n";
        } else if (operacion == 'V' || operacion == 'v') {
            if (cantidad <= tienda[pos].existencia) {
                tienda[pos].existencia -= cantidad;
                cout << "Venta registrada.\n";
            } else {
                cout << "Existencia insuficiente. Venta rechazada.\n";
            }
        } else {
            cout << "Operacion no valida.\n";
        }

        cout << "\nOperacion (C = compra, V = venta, 0 = terminar): ";
        cin >> operacion;
    }
}

void Inventario(Producto tienda[], int n) {
    cout << "\n--- INVENTARIO ACTUALIZADO ---\n";

    for (int i = 0; i < n; i++) {
        cout << "\nClave: " << tienda[i].clave
             << "\nNombre: " << tienda[i].nombre
             << "\nExistencia: " << tienda[i].existencia << '\n';
    }
}

int main() {
    Producto TIENDA[100];
    int n;

    do {
        cout << "Cantidad de productos (1-100): ";
        cin >> n;
    } while (n < 1 || n > 100);

    Lectura(TIENDA, n);
    Transacciones(TIENDA, n);
    Inventario(TIENDA, n);

    return 0;
}

#include <iostream>
using namespace std;

void trueque(int *x, int *y) {
    int tem;

    tem = *x;
    *x = *y;
    *y = tem;
}

int suma(int x) {
    return x + x;
}

int main() {
    int x = 5, y = 10, z;

    // Llamadas del ejercicio:

    // 1. trueque(suma(&x), &x);  INCORRECTA
    // 2. trueque(3, 4);          INCORRECTA
    // 3. suma(10);               CORRECTA
    // 4. y = suma(10);           CORRECTA
    // 5. z = trueque(&x, &y);    INCORRECTA
    // 6. trueque(&x, &y);        CORRECTA

    trueque(&x, &y);

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    return 0;
}

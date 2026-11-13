#include <iostream>
using namespace std;

int main() {
    int MED, SME;
    double VAL, RES;

    cout << "1. Longitud\n2. Volumen\n3. Peso\n";
    cout << "Seleccione el tipo: ";
    cin >> MED;

    cout << "Ingrese el valor: ";
    cin >> VAL;

    cout << "Seleccione la conversion:\n";

    if (MED == 1) {
        cout << "1. Pulgadas a milimetros\n";
        cout << "2. Yardas a metros\n";
        cout << "3. Millas a kilometros\n";
        cout << "4. Pies cuadrados a metros cuadrados\n";
        cout << "5. Yardas cuadradas a metros cuadrados\n";
        cout << "6. Acres a hectareas\n";
        cout << "7. Millas cuadradas a kilometros cuadrados\n";
        cin >> SME;

        switch (SME) {
            case 1: RES = VAL * 25.40; break;
            case 2: RES = VAL * 0.9144; break;
            case 3: RES = VAL * 1.6093; break;
            case 4: RES = VAL * 0.09290; break;
            case 5: RES = VAL * 0.8361; break;
            case 6: RES = VAL * 0.4047; break;
            case 7: RES = VAL * 2.59; break;
            default: cout << "Conversion incorrecta"; return 0;
        }
    }
    else if (MED == 2) {
        cout << "1. Pies cubicos a metros cubicos\n";
        cout << "2. Yardas cubicas a metros cubicos\n";
        cout << "3. Pintas a litros\n";
        cout << "4. Galones a litros\n";
        cin >> SME;

        switch (SME) {
            case 1: RES = VAL * 0.02832; break;
            case 2: RES = VAL * 0.7646; break;
            case 3: RES = VAL * 0.56826; break;
            case 4: RES = VAL * 4.54609; break;
            default: cout << "Conversion incorrecta"; return 0;
        }
    }
    else if (MED == 3) {
        cout << "1. Onzas a gramos\n";
        cout << "2. Libras a kilogramos\n";
        cout << "3. Toneladas inglesas a toneladas\n";
        cin >> SME;

        switch (SME) {
            case 1: RES = VAL * 28.35; break;
            case 2: RES = VAL * 0.45359; break;
            case 3: RES = VAL * 1.0160; break;
            default: cout << "Conversion incorrecta"; return 0;
        }
    }
    else {
        cout << "Tipo incorrecto";
        return 0;
    }

    cout << "Resultado de la conversion: " << RES;
    return 0;
}

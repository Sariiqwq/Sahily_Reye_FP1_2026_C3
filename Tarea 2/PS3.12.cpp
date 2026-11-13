#include <iostream>
using namespace std;

int main() {
    int NUM;

    cout << "Ingrese NUM: ";
    cin >> NUM;

    for (int i = 2; i < NUM; i++) {
        bool PRIMO = true;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                PRIMO = false;
                break;
            }
        }

        if (PRIMO)
            cout << i << " ";
    }

    return 0;
}

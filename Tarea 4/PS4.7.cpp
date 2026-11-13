#include <iostream>

using namespace std;

int main()
{#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    if (esPrimo(n))
        cout << "Es primo.";
    else
        cout << "No es primo.";

    return 0;
}
    cout << "Hello world!" << endl;
    return 0;
}

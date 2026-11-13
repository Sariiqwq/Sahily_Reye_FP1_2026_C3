#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Ingrese N: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }

    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}

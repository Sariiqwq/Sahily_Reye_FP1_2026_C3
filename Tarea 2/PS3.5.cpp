#include <iostream>
using namespace std;

int main() {
    int N;
    long long PRODUCTO = 1;

    cout << "Ingrese N: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
        PRODUCTO *= i;

    cout << "Productoria: " << PRODUCTO;
    return 0;
}

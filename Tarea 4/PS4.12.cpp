
#include <iostream>
using namespace std;

long long K = 5;

long long f1(void);
int f2(void);
int f3(void);
long long f4(void);

int main() {
    for (int i = 1; i <= 4; i++) {
        cout << "Vuelta " << i << endl;

        cout << "f1: " << f1() << endl;
        cout << "f2: " << f2() << endl;
        cout << "f3: " << f3() << endl;
        cout << "f4: " << f4() << endl;

        cout << endl;
    }

    return 0;
}

long long f1(void) {
    K *= K;
    return K;
}

int f2(void) {
    int K = 3;
    K++;
    return K;
}

int f3(void) {
    static int K = 6;
    K += 3;
    return K;
}

long long f4(void) {
    int K = 4;
    K = K + ::K;
    return K;
}

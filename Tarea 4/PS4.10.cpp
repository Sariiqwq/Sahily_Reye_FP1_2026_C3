#include <iostream>
using namespace std;

int a, b, c, d;

int pal(int x, int y) {
    int c;

    b = x * y;
    c = b + y;
    x++;
    y = y * (y + 1);

    cout << b << " " << c << " " << x << " " << y << endl;

    return x;
}

int main() {
    a = 2;
    c = 3;
    d = 5;

    a = pal(c, d);
    cout << a << " " << b << " " << c << " " << d << endl;

    b = 4;
    b = pal(b, a);
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}

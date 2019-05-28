#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int i = 0;
    int j = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a + b == c || a - b == 2 * c) {
        for (i = 1; i < 10; i++) {
            cout << i << endl;
        }
    }
    else
    {
        for (j = 11; j < 20; j++) {
            cout << j << endl;
        }
    }
    if ((!a && !(b == c)) && a == c) {
        while(a > b) {
            cout << a << endl;
            a = a - 1;
        }
        while(b < c) {
            cout << b * b << endl;
            b = b + 2;
        }
    }
    for (i = 0; i < a; i++) {
        while(i < 10) {
            if (i < 5) {
                cout << i << endl;
            }
            else
            {
                cout << i * a << endl;
            }
        }
        cin >> d;
        if (d % 0) {
            cout << 1 << endl;
        }
    }
}

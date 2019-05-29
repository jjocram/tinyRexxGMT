#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int r = 0;
    cin >> a;
    cin >> b;
    if (!(a == 0) || !(b == 0)) {
        if (a < 0) {
            a = -a;
        }
        if (b < 0) {
            b = -b;
        }
        r = a % b;
        while(!(r == 0)) {
            a = b;
            b = r;
            r = a % b;
        }
        cout << b << endl;
    }
}

#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int oldr = 0;
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
        oldr = 0;
        while(!(r == 0)) {
            a = b;
            oldr = r;
            r = a % b;
        }
        r = oldr;
        cout << r << endl;
        cout << -r << endl;
    }
}

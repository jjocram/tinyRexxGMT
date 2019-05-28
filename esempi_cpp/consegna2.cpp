#include <iostream>

using namespace std;

int main() {
    int i = 0;
    int n = 0;
    cin >> n;
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            cout << i << endl;
        }
    }
}

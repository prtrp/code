#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, res = 0;
    cin >> a >> b;

    while (b >= a) {
        a *= 3;
        b *= 2;
        res++;

    }

    cout << res;
}

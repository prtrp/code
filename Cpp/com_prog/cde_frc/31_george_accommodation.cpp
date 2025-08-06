#include <iostream>

using namespace std;

int main() {
    // n = number of rooms
    int n;
    cin >> n;

    int p, q, r = 0;
    while(n--) {
        cin >> p >> q;
        if (p+2 <= q) r++;
    }
    cout << r;
}

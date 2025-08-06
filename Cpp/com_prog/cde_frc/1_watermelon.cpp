#include <iostream>

using namespace std;

int main() {
    int x = 0;
    cin >> x;

    if (x == 2) { cout << "NO"; return 0;}

    if ((x % 2) == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

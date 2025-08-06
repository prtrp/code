#include <iostream>

using namespace std;

int main() {
    int i;
    cin >> i;

    if (i % 4 == 0 || i % 7 == 0 || i % 47 == 0 || i % 74 == 0 || i % 447  == 0 || i % 474 == 0 || i % 444 == 0|| i % 477 == 0) {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}

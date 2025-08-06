#include <iostream>

using namespace std;

int main() {
    int x = 0;
    cin >> x;

    int sol = x/5;

    if (x % 5 != 0) sol++;

    cout << sol << "\n";
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int a, b, i; 
    cin >> i;
    while (i--) {
        cin >> a >> b;
        cout << (a%b ? b - a%b : 0) << "\n";

    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    double n, m, j=0, i;

    cin >> n;
    m = n;
    while (m--) {
        cin >> i;
        j += i;
    }
    
    cout << (double)(j/n);
    return 0;
}

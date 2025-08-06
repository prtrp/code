#include <iostream>

using namespace std;

int main() {
    long long k, h=0, n; 
    cin >> k >> h;    

    if (k % 2 == 0) {
        n = k/2;
    } 
    else {
        n = (k/2)+1;
    }

    if (h <= n) {
        h = 2*(h-1)+1;

    } else {
        h = 2*((h-n));
    }

    cout << h << "\n";
    return 0;
}

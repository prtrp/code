#include <iostream>

using namespace std;

int main() {
    int v, w, r=0, tmp = 0;
    cin >> v;

    while (cin >> v >> w) {
        tmp += (w - v);
        if (tmp > r) r = tmp;
    }
    
    cout << r << "\n";
}

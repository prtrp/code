#include <iostream>

using namespace std;

int main() {
    int n, m, r=1;
    cin >> n;

    cin >> m;
    while((n-1) > 0) {
        int tmp;

        tmp = m;
        cin >> m;

        if (tmp != m) {
            r++;
        }
        n--;
    }

    cout << r;
}

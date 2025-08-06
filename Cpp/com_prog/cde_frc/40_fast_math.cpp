#include <iostream>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;

    for (int i = 0; i < m.size(); i++) {
        cout << (n[i] == m[i] ? "0" : "1");
    }
    return 0;
}

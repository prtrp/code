#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    while(n--) {cin >> m; if (m == 1) {cout << "HARD"; return 0;}}
    cout << "EASY";
    return 0;
}

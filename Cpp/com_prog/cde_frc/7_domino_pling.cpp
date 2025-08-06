#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int area = m*n;
    int dominos = (area) / 2;

    cout << dominos << "\n";
    return 0;
}

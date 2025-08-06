#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m; cin >> n;

    vector<int> coins(n); 
    for (int i = 0; i < n; i++) {
        cin >> m;
        coins[i] = m;
    }

    sort(coins.begin(), coins.end());

    int a = 0, b = 0, c = 0;

    for(int i = 0; i < n; i++) {
        a += coins[i];
    }

    for (int i = 0; i < n; i++) {
        b += coins[n-i-1];
        c++;
        if (b > (a/2)) {
            cout << c;
            return 0;
        }
    }
    return 0;
}

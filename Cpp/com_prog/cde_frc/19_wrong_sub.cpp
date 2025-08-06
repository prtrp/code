#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /* n = number to subtract */
    /* k = how may times */
    ll n, k;
    cin >> n >> k;

    while (k--) (n % 10) ? n-- : n /= 10;

    cout << n << "\n";
}

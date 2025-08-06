#include <iostream>


typedef long long ll;

using namespace std;

int main() {
    ll j, i = 0;
    cin >> j;

    i = (j % 2 == 0 ? j/2 : -(j+1)/2);
    cout << i << "\n";
    return 0;
}


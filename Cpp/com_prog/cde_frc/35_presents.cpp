#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, tmp = 0; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> w(n); 
    for (int i = 0; i < n; i++) w[i] = v[i];

    for (int i = 0; i < n; i++) {
        int tmp = v[i];
        w[tmp-1] = i+1;

    }

    for (int i = 0; i < n; i++) cout << w[i] << " ";
    return 0;
}

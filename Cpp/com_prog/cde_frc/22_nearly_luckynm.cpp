#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ll k;
    cin >> k;

    string s = to_string(k);

    int result = 0;
    for(char c : s) {
        if (c == '4' || c == '7') {
            result++;
        }

    }

    string s2 = to_string(result); 

    for (char c : s2) {
        if (c != '4' && c != '7') {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    return 0;
}

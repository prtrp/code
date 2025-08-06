#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "NO" << "\n";
        return 0;
    }

    reverse(s2.begin(), s2.end());

    for (int i = 0; i < (int)s1.size(); i++) {
        if (s1[i] != s2[i]) {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    return 0;
}

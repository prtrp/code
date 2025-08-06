#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int size = s1.size();

    for(int i = 0; i < size; i++) {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);

        if (c1 > c2) { cout << 1 << "\n"; return 0; }
        if (c1 < c2) { cout << -1 << "\n"; return 0; }
    }

    cout << 0 << "\n";
    return 0;

}

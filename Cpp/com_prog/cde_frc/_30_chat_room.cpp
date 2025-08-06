#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t = "hello"; cin >> s;
    int j = 0;

    for (char c : s) if (c==t[j]) j++;
    cout << (j == 5 ? "YES":"NO");
    return 0;
}

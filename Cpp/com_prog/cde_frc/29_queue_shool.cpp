#include <iostream>

using namespace std;

int main() {
    // n = number of children
    // t = timpe after queue will transform
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    while(t--) for (int i = 0; i < n; i++) if (s[i] == 'B' && s[i+1] == 'G') {swap(s[i], s[i+1]); i++;}

    for (int i = 0; i < n; i++) cout << s[i];
    return 0;
}


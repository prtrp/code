#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int result = 1;
    for(int i = 0; i < (int)s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            result++;
            if( result >= 7) { cout << "YES" << "\n"; return 0; }
        }
        else {
            result = 1;
        }
    }

    cout <<  "NO" << "\n";
    return 0;
}

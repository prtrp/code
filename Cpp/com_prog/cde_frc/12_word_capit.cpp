#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;
    cin >> s1;

    if(s1[0] >= 'A' && s1[0] <= 'Z') {
        cout << s1 << "\n";
        return 0;
    }
    else {
        s1[0] -= 32;
    }
    cout << s1 << "\n";
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);


    for (char c : s1) {
        if(c != '+') s2 += c; 
    }

    int size = s2.size();
    sort(s2.begin(), s2.end());

 
    for (int i = 0; i < size; i++) {
         cout << s2[i]; 
        if (i < size-1) {
            cout << "+";
        }
    }
    cout << "\n";

    return 0;
}

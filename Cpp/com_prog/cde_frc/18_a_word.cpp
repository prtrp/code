#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;

    int lower = 0;
    int upper = 0;

    for (char c : s) {
        if (c <= 90) {
            upper++;
        } 
        else if (c >= 97) {
            lower++;
        }
    }

    if (lower >= upper) {
        transform(s.begin(), s.end(), s.begin(),
                  [](char c){return tolower(c);});
    }
    else {
        transform(s.begin(), s.end(), s.begin(),
                  [](char c){return toupper(c);});
    }

    cout << s << "\n";
    
}

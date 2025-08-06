#include <iostream>
#include <string>

using namespace std;

int main() {
    // n = number of games
    // s = winner
    int n;
    string s;

    cin >> n >> s;

    int a = 0;
    int d = 0;

    for(char c : s) {
        c == 'A' ? a++ : d++;
    }

    if (a == d) cout << "Friendship" << "\n";
    else if (a < d) cout << "Danik" << "\n";
    else cout << "Anton" << "\n";
}

#include <iostream>

using namespace std;

int main() {

    // n = number of friends
    // h = height of fence
    int n, h, result = 0;
    cin >> n >> h;

    int friends;
    while(n--) {
        cin >> friends;

        result += (friends <= h ? 1 : 2);
    }

    cout << result << "\n";
}

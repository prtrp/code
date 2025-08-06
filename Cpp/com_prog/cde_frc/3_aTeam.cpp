#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    int sol = 0;

    cin >> n;

    vector<vector<int>> s2d(n, vector<int>(3));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> s2d[i][j];
        }
        if (s2d[i][0] + s2d[i][1] + s2d[i][2] >= 2){
            ++sol;
        }
    }
    cout << sol;
    return 0;
}


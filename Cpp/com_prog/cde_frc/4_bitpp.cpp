#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x = 0;
    int res = 0;

    cin >> x;

    vector<string> line(x);
    
    for(int i = 0; i < x; i++) {
        cin >> line[i];
        if ((line[i][0] + line[i][1] + line[i][2]) == 174) {
            res++;
        }
        else if ((line[i][0] + line[i][1] + line[i][2]) == 178) {
            res--;
        }
    }

    cout << res << "\n";
}

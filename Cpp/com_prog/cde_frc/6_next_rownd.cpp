#include <iostream>
#include <vector>

using namespace std;

int main() {
    // n are the partecipants
    // k are the address of value
    int n, k;
    cin >> n >> k;

    if (n == 0 || k < 0) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    vector<int> memb(n);

    // = ^.^ =
    for (int i = 0; i < n; i++) {
        cin >> memb[i];
    }


    if (memb[k-1] == 0) {
        for (int i = 0; i < n; i++) {
            if (memb[i] > 0) {
                res++;
            }
            else{
                cout << res << endl;
                return 0;
            }
        }
    }

    int tmp = memb[k-1];
    for (int i = 0; i < n; i++) {
        if(memb[i] >= tmp && tmp > 0) {
            res++;
        }
        else {
            cout << res << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}

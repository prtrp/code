#include <iostream>

using namespace std;

int main() {
    long long arr[4];
    long long a, b=0;

    for (int i = 0; i < 4; i++) {
        cin >> a;
        arr[i] = a;
    }
    
    for (int i = 0; i < 4; i++) {
        for(int j = i; j < 3; j++) {
            if (arr[i] == arr[j+1]) {
                b++;
                break;
            }
        }
    }

    cout << b << "\n";
    return 0;
}

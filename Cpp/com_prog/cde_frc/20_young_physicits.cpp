#include <iostream>

using namespace std;

int main() {
    int rows;
    int ind0 = 0, ind1 = 0, ind2 = 0;
    cin >> rows;

    int vec;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vec;
            if (j == 0) {
                ind0 += vec;
            }
            else if (j == 1) {
                ind1 += vec;
            }
            else if (j == 2) {
                ind2 += vec;
            }
        }
    }

    cout << ((ind0 == 0 && ind1 == 0  && ind2 == 0) ? "YES" : "NO") << "\n";
}

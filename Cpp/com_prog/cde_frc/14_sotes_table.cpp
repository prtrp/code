#include <iostream>

using namespace std;

int main() {
    int size = 0;
    string color;

    cin >> size;
    cin >> color;

    int remove = 0;
    for (int i = 0; i < size; i++) {
        if (color[i] == color [i+1]) {
            remove++;
        }
    }
    cout << remove << "\n";
    return 0;
}

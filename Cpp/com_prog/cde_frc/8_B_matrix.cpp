#include <iostream>

using namespace std;

int main() {
    int tmp = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> tmp;
            if (tmp == 1) {
                goto exit;
            }
            row++;
        }
        row = 0;
        col++;
    }

exit:

    tmp = 0;

    while (col < 2) { col++; tmp++; }
    while (col > 2) { col--; tmp++; }

    while (row < 2) { row++; tmp++; }
    while (row > 2) { row--; tmp++; }

    cout << tmp << "\n";
    return 0;
}

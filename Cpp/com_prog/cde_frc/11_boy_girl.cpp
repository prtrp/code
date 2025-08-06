#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;
    cin >> s1;

    string buff;

    // per ogni carattere nella stringa data
    for (char c : s1) {
        // per verificare se eisite un duplicato
        bool duplicate = false;

        // per ogni carattere nella stringa 
        // senze duplicati
        for (char d : buff) {

            // se ho un duplicato
            if (c == d) {
                duplicate = true;
                // interrompo il confronto perche ho 
                // gia un duplicato
                break;
            }
        }
        // se non e duplicato allora lo aggiungo
        if (!duplicate) {
            buff += c;
        }
    }

    cout << (buff.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!") << "\n";
}

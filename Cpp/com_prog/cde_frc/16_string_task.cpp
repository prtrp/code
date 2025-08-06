#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string word;
    string result;
    cin >> word;


    transform(word.begin(), word.end(), word.begin(), 
              [](unsigned char c){return tolower(c);});

    for (char c : word) {
        if ( c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u' || c == 'y') {
            continue;
        } 
        else {
            result += '.';
            result += c;

        }
    }

    cout << result << "\n";
}

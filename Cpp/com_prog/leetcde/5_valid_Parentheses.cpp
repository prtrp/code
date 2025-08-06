#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution{

public:
    bool isValid(string s) {
        stack<char> phar;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                phar.push(c);
            }
            else {
                if(phar.empty()) {
                    return false;
                }

                char top = phar.top();
                phar.pop();

                if (c == ')' && top != '(' || 
                    c == ']' && top != '[' ||
                    c == '}' && top != '{') {
                    return false;
                }
            }
        }
        return phar.empty();
    }
};

int main() {
    Solution sol;
    if(sol.isValid("(]")) cout << "TURE\n";
    else cout << "FALSE\n";
    return 0;

}


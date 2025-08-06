#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs[0].size();
        string s;
        for (int i = 0; i < strs.size()-1; i++) { // O(n) time complx
            int tmp = strs[i].size() < strs[i].size() ? strs[i].size() : strs[i+1].size();
            size = size > tmp ? tmp : size;
        }

        for (int i = 0; i < size; i++) { // O(n*m)
            for (int j = 0; j < strs.size()-1; j++) {
                if (strs[j][i] != strs[j+1][i]) {
                    return s;
                }
            }
            s += strs[0][i];
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};

    string s = sol.longestCommonPrefix(strs);
    for (char c: s) cout << c;
    cout << "\n";
    return 0;
}


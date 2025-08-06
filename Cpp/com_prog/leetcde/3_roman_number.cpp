#include <iostream>
#include <vector>

using namespace std;

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000


class Solution {
private:
    static constexpr int charToVal(char c) {
            switch (c) {
                case 'M': return M;
                case 'D': return D; 
                case 'C': return C; 
                case 'L': return L; 
                case 'X': return X; 
                case 'V': return V; 
                case 'I': return I; 
                default : return 0;
            }
    }

public:


    int romanToInt(string s) {

        int size = s.size();
        vector <int> n(size);
        for (int i = 0; i < size; i++) {
            n[i] = charToVal(s[i]);
        }
        int result = 0;
        for (int i = 0; i < size-1; i++) {
            if (n[i] >= n[i+1]) {
                result += (n[i]);
            }
            else {
                result -= n[i];
            }
        }
        result += n[size-1];
        return result;
    }

    int romanTOIntBest(string s) {
        return 0;
    }
};


int main() {
    Solution sol;
    cout << sol.romanToInt("LVIII") << "\n";
    return 0;
}

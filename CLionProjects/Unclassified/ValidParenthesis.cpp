#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return isValidString(0, 0, s, memo);
    }
private:
    bool isValidString(int index, int openCount, const string &str, vector<vector<int>> &memo) {
        if (index == str.size()) {
            return (openCount == 0);
        }
        if (openCount < 0) return false; // Early pruning (invalid state)

        if (memo[index][openCount] != -1) {
            return memo[index][openCount];
        }

        bool isValid = false;
        if (str[index] == '*') {
            isValid |= isValidString(index + 1, openCount + 1, str, memo); // '*' as '('
            if (openCount) {
                isValid |= isValidString(index + 1, openCount - 1, str, memo); // '*' as ')'
            }
            isValid |= isValidString(index + 1, openCount, str, memo); // '*' as empty
        } else {
            if (str[index] == '(') {
                isValid = isValidString(index + 1, openCount + 1, str, memo);
            } else if (str[index] == ')') {
                if (openCount) {
                    isValid = isValidString(index + 1, openCount - 1, str, memo);
                } else {
                    isValid = false;
                }
            }
        }

        return memo[index][openCount] = isValid;
    }
};

int main() {
    Solution sol;
    vector<string> testCases = {
        "((",
        "(*(*)*)",   // true
    };

    for (const string& s : testCases) {
        cout << "Input: " << s << " → Output: "
             << (sol.checkValidString(s) ? "true" : "false") << endl;
    }

    return 0;
}

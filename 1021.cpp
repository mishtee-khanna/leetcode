#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;

        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result += c;
                }
                opened++;
            } else {
                opened--;
                if (opened > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "(()())(())";
    string s2 = "(()())(())(()(()))";
    string s3 = "()()";

    cout << "Input:  \"" << s1 << "\"\nOutput: \"" << sol.removeOuterParentheses(s1) << "\"\n\n";
    cout << "Input:  \"" << s2 << "\"\nOutput: \"" << sol.removeOuterParentheses(s2) << "\"\n\n";
    cout << "Input:  \"" << s3 << "\"\nOutput: \"" << sol.removeOuterParentheses(s3) << "\"\n";

    return 0;
}

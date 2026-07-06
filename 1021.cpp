#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If depth > 0, this '(' is inside a primitive string
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else {
                // Decrement depth first for a closing parenthesis
                depth--;
                // If depth > 0, this ')' is inside a primitive string
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Example 1: "(()())(())" -> "()()()"
    string s1 = "(()())(())";
    cout << "Input:  " << s1 << "\nOutput: " << solver.removeOuterParentheses(s1) << "\n\n";
    
    // Example 2: "(()())(())(()(()))" -> "()()()()(())"
    string s2 = "(()())(())(()(()))";
    cout << "Input:  " << s2 << "\nOutput: " << solver.removeOuterParentheses(s2) << "\n\n";
    
    return 0;
}
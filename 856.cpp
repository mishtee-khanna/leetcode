#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        // Fixed the typo: changed s.length(emini) to s.length()
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(i > 0 && s[i - 1] == '('){
                    score += 1 << depth;
                }
            }
        }
        return score;
    }
};

int main() {
    Solution sol;
    
    // Test cases to verify the logic locally
    string test1 = "()";
    string test2 = "(())";
    string test3 = "(()(()))";
    
    cout << "Score of " << test1 << " : " << sol.scoreOfParentheses(test1) << "\n";
    cout << "Score of " << test2 << " : " << sol.scoreOfParentheses(test2) << "\n";
    cout << "Score of " << test3 << " : " << sol.scoreOfParentheses(test3) << "\n";
    
    return 0;
}

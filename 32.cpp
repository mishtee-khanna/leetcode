#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "(()";
    cout << "Input: " << s1 << "\nOutput: " << solution.longestValidParentheses(s1) << "\n\n";
    
    // Example 2
    string s2 = ")()())";
    cout << "Input: " << s2 << "\nOutput: " << solution.longestValidParentheses(s2) << "\n\n";
    
    // Example 3
    string s3 = "";
    cout << "Input: " << s3 << "\nOutput: " << solution.longestValidParentheses(s3) << "\n";
    
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        
        // Step 1: Pair up the matching parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        // Step 2: Traverse the string and build the result
        string result = "";
        int i = 0;
        int direction = 1;
        
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                // "Teleport" to the matching bracket and reverse direction
                i = pair[i];
                direction = -direction;
            } else {
                // Append standard characters
                result += s[i];
            }
            i += direction;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "(abcd)";
    cout << "Input: " << s1 << "\nOutput: " << sol.reverseParentheses(s1) << "\n\n";
    
    // Example 2
    string s2 = "(u(love)i)";
    cout << "Input: " << s2 << "\nOutput: " << sol.reverseParentheses(s2) << "\n\n";
    
    // Example 3
    string s3 = "(ed(et(oc))el)";
    cout << "Input: " << s3 << "\nOutput: " << sol.reverseParentheses(s3) << "\n\n";

    return 0;
}

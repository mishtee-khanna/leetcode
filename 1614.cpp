#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int current_depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                max_depth = max(max_depth, current_depth);
            } else if (c == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};

int main() {
    Solution sol;
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Max depth: " << sol.maxDepth(s1) << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int p[2] = {0};
        for (char c : s) {
            bool isLeft = (c == '(');
            p[0] += isLeft;
            p[p[0] <= 0] += (1 - ((p[0] > 0) << 1)) * (!isLeft);
        }
        return p[0] + p[1];
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "())";
    string s2 = "(((";
    string s3 = "()";
    string s4 = "()))((";

    cout << "Input: \"" << s1 << "\" -> Moves: " << sol.minAddToMakeValid(s1) << endl;
    cout << "Input: \"" << s2 << "\" -> Moves: " << sol.minAddToMakeValid(s2) << endl;
    cout << "Input: \"" << s3 << "\" -> Moves: " << sol.minAddToMakeValid(s3) << endl;
    cout << "Input: \"" << s4 << "\" -> Moves: " << sol.minAddToMakeValid(s4) << endl;

    return 0;
}

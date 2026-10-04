#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0; 
        int leftMax = 0; 
        
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { // c == '*'
                leftMin--; 
                leftMax++; 
            }
            
            if (leftMax < 0) {
                return false;
            }
            
            if (leftMin < 0) {
                leftMin = 0;
            }
        }
        
        return leftMin == 0;
    }
};

int main() {
    Solution sol;
    string s = "(*))";
    if (sol.checkValidString(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}

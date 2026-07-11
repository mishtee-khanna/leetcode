#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        
        // XOR all characters in string s
        for (char c : s) {
            result ^= c;
        }
        
        // XOR all characters in string t
        for (char c : t) {
            result ^= c;
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "abcd", t1 = "abcde";
    cout << "Test 1: '" << solver.findTheDifference(s1, t1) << "' (Expected: 'e')" << endl;
    
    // Test Case 2
    string s2 = "", t2 = "y";
    cout << "Test 2: '" << solver.findTheDifference(s2, t2) << "' (Expected: 'y')" << endl;
    
    return 0;
}
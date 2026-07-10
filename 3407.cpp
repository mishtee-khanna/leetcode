#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t starPos = p.find('*');
        
        string prefix = p.substr(0, starPos);
        string suffix = p.substr(starPos + 1);
        
        size_t prefixIdx = s.find(prefix);
        if (prefixIdx == string::npos) {
            return false;
        }
        
        size_t suffixIdx = s.find(suffix, prefixIdx + prefix.length());
        
        return suffixIdx != string::npos;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "leetcode";
    string p1 = "ee*e";
    cout << "Test 1: " << (solver.hasMatch(s1, p1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2
    string s2 = "car";
    string p2 = "c*v";
    cout << "Test 2: " << (solver.hasMatch(s2, p2) ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test Case 3
    string s3 = "luck";
    string p3 = "u*";
    cout << "Test 3: " << (solver.hasMatch(s3, p3) ? "true" : "false") << " (Expected: true)" << endl;
    
    return 0;
}
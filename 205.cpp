#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base condition: strings of different lengths cannot be isomorphic
        if (s.length() != t.length()) return false;
        
        // Arrays to store the 1-based index of the last seen position for each character
        vector<int> mapS(256, 0);
        vector<int> mapT(256, 0);
        
        for (int i = 0; i < s.length(); i++) {
            // If the previous positions don't match, they aren't mapping correctly
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            
            // Record the current position (using i + 1 to avoid conflict with the default 0)
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "egg", t1 = "add";
    cout << "Test 1: " << (solver.isIsomorphic(s1, t1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2
    string s2 = "foo", t2 = "bar";
    cout << "Test 2: " << (solver.isIsomorphic(s2, t2) ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test Case 3
    string s3 = "paper", t3 = "title";
    cout << "Test 3: " << (solver.isIsomorphic(s3, t3) ? "true" : "false") << " (Expected: true)" << endl;
    
    return 0;
}
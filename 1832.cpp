#include <iostream>
#include <string>
#include <unordered_set>

using namespace std; 

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen;
        
        for (char c : sentence) {
            seen.insert(c);
        }
        
        return seen.size() == 26;
    }
};

int main() {
    Solution solver;
    string sentence1 = "thequickbrownfoxjumpsoverthelazydog";
    string sentence2 = "leetcode";
    
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test Case 1: " << solver.checkIfPangram(sentence1) << " (Expected: true)" << endl;
    cout << "Test Case 2: " << solver.checkIfPangram(sentence2) << " (Expected: false)" << endl;

    return 0;
}
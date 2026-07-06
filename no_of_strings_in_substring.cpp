#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        
        for (const string& pattern : patterns) {
            // Check if the pattern is found within 'word'
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    Solution solver;
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";
    
    cout << "Number of matching substrings: " << solver.numOfStrings(patterns, word) << endl;
    
    return 0;
}
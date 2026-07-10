#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int wordIndex = 1;
        
        while (ss >> word) {
            if (word.find(searchWord) == 0) {
                return wordIndex;
            }
            wordIndex++;
        }
        
        return -1;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string sentence1 = "i love eating burger";
    string searchWord1 = "burg";
    cout << "Test 1 Result: " << solver.isPrefixOfWord(sentence1, searchWord1) << " (Expected: 4)" << endl;
    
    // Test Case 2
    string sentence2 = "this problem is an easy problem";
    string searchWord2 = "pro";
    cout << "Test 2 Result: " << solver.isPrefixOfWord(sentence2, searchWord2) << " (Expected: 2)" << endl;
    
    // Test Case 3
    string sentence3 = "i am tired";
    string searchWord3 = "you";
    cout << "Test 3 Result: " << solver.isPrefixOfWord(sentence3, searchWord3) << " (Expected: -1)" << endl;
    
    return 0;
}
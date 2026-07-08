#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        
        // Extract all words from the string
        while (ss >> word) {
            words.push_back(word);
        }
        
        // If the number of characters doesn't match the number of words, it's impossible
        if (pattern.length() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // Check mapping from char to word
            if (charToWord.count(c)) {
                if (charToWord[c] != w) return false;
            } else {
                charToWord[c] = w;
            }
            
            // Check mapping from word to char
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) return false;
            } else {
                wordToChar[w] = c;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    
    string pattern = "abba";
    string s = "dog cat cat dog";
    
    if (solver.wordPattern(pattern, s)) {
        cout << "True: The string matches the pattern." << endl;
    } else {
        cout << "False: The string does not match the pattern." << endl;
    }
    
    return 0;
}
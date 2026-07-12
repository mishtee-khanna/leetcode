#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int sLen = s.length();
        
        // Count frequencies of words in the input array
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }
        
        // Travel across the word length offsets to hit all alignments
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> currentMap;
            int count = 0; // Tracks number of valid words in the current window
            
            // Slide the window block by block
            while (right + wordLen <= sLen) {
                // Pull out the next word block
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                // If the word exists in our target list
                if (wordMap.find(word) != wordMap.end()) {
                    currentMap[word]++;
                    count++;
                    
                    // If we have more occurrences of 'word' than allowed, slide 'left' forward
                    while (currentMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // If the number of correctly matched words equals wordCount, we found an index
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word encountered: Reset the window completely
                    currentMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> res1 = solver.findSubstring(s1, words1);
    cout << "Test 1: ";
    for (int idx : res1) cout << idx << " ";
    cout << "(Expected: 0 9)" << endl;
    
    // Test Case 2
    string s2 = "wordgoodgoodgoodword3word";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> res2 = solver.findSubstring(s2, words2);
    cout << "Test 2: ";
    for (int idx : res2) cout << idx << " ";
    cout << "(Expected: )" << endl; // Empty mapping expected
    
    return 0;
}
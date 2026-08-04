#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i = 0; i < word.length(); i++){
            if(isupper(word[i])) count++;
        }

        return (count == word.length() || count == 0 || count == 1 && isupper(word[0]));
        
    }
};

int main() {
    Solution sol;

    // Example usage
    string word = "USA"; // Input word to check

    bool isValid = sol.detectCapitalUse(word);
    cout << "The word \"" << word << "\" uses capital letters correctly: " << (isValid ? "true" : "false") << endl;

    return 0;
}
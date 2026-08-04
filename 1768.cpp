#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string result = "";
        while(i < word1.length() || j < word2.length()){
            if(i < word1.length()) result += word1[i++];
            if(j < word2.length()) result += word2[j++];
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example usage
    string word1 = "abc"; // First input string
    string word2 = "pqr"; // Second input string

    string mergedString = sol.mergeAlternately(word1, word2);
    cout << "The merged string is: " << mergedString << endl;

    return 0;
}
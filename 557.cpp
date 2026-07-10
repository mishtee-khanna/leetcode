#include<bits/stdc++.h>
using namespace std;

string reverseAlternateWords(string str) {
    stringstream ss(str);
    vector<string> words;
    string word;

    // Extract words
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse every alternate word (2nd, 4th, 6th...)
    for (int i = 1; i < words.size(); i ++) {
        reverse(words[i].begin(), words[i].end());
    }

    // Reconstruct the sentence
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main() {
    string str;
    getline(cin, str);

    cout << reverseAlternateWords(str);

    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseSentence(string s) {
    stringstream ss(s);
    vector<string> words;
    string word;

    // Split sentence into words
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join words back into a sentence
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main() {
    string s;
    getline(cin, s);

    cout << reverseSentence(s);

    return 0;
}
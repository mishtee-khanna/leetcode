#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int blocks = 1;

        for(int i = 1; i < word.length(); i++){
            if(word[i] <= word[i - 1]){
                blocks++;
            }
        }

        return blocks * 3 - word.length();
    }
};

int main(){
    Solution sol;

    // Example usage
    string word = "ac"; // Input string

    int minAdditions = sol.addMinimum(word);
    cout << "The minimum number of characters to add is: " << minAdditions << endl;

    return 0;
}
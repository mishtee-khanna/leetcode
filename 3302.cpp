#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_match(m + 1, -1);
        last_match[m] = n;

        int ptr = n - 1;
        for(int i = m - 1; i >= 0; i--){
            while(ptr >= 0 && word1[ptr] != word2[i]) ptr--;
            last_match[i] = ptr;
            if(ptr >= 0) ptr--;
        }

        vector<int> ans;
        bool used_change = false;
        int word1_index  = 0;

        for(int i = 0; i < m; i++){
            bool matched = false;
            while(word1_index < n){
                if(word1[word1_index]== word2[i]){
                    ans.push_back(word1_index);
                    word1_index++;
                    matched = true;
                    break;
                }

                else if(!used_change && last_match[i + 1] > word1_index){
                    ans.push_back(word1_index);
                    used_change = true;
                    word1_index++;
                    matched = true;
                    break;
                }
                word1_index++;
            }
            if(!matched) return {};
            
        }

        
        return ans;
    }

};

int main(){
    Solution sol;

    string word1 = "abcde";
    string word2 = "ace";

    vector<int> result = sol.validSequence(word1, word2);
    if(result.empty()){
        cout << "No valid sequence found." << endl;
    } else {
        cout << "Valid sequence indices: ";
        for(int index : result){
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}










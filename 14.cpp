#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.empty()) return "";

        string prefix = str[0];

        for(int i = 1; i < str.size(); i++){
            while(str[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.length() - 1);
                if(prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main(){
    Solution sol;
    vector<string> str = {"flower", "flow", "flight"}; // Example input
    string result = sol.longestCommonPrefix(str);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}
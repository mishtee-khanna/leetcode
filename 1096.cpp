#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        unordered_set<string> resSet = dfs(expression, i);
        vector<string> res(resSet.begin(), resSet.end());
        sort(res.begin(), res.end());
        return res;
    }

private:
    unordered_set<string> dfs(const string& s, int& i) {
        unordered_set<string> res;
        unordered_set<string> cur = {""};
        
        while (i < s.length()) {
            if (s[i] == '{') {
                i++; // Skip '{'
                unordered_set<string> sub = dfs(s, i);
                cur = combine(cur, sub);
            } else if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++; // Skip ','
            } else if (s[i] == '}') {
                i++; // Skip '}'
                break;
            } else {
                unordered_set<string> sub = {string(1, s[i])};
                cur = combine(cur, sub);
                i++; 
            }
        }
        res.insert(cur.begin(), cur.end());
        return res;
    }
    
    unordered_set<string> combine(const unordered_set<string>& a, const unordered_set<string>& b) {
        unordered_set<string> combined_set;
        for (const string& x : a) {
            for (const string& y : b) {
                combined_set.insert(x + y);
            }
        }
        return combined_set;
    }
};

int main() {
    Solution sol;
    
    string expression1 = "{a,b}{c,{d,e}}";
    vector<string> result1 = sol.braceExpansionII(expression1);
    
    cout << "Input: " << expression1 << "\nOutput: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]\n\n";
  
    string expression2 = "{{a,z},a{b,c},{ab,z}}";
    vector<string> result2 = sol.braceExpansionII(expression2);
    
    cout << "Input: " << expression2 << "\nOutput: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]\n";

    return 0;
}

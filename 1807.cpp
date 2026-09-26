#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool in_bracket = false;
        
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                if (dict.find(current_key) != dict.end()) {
                    result += dict[current_key];
                } else {
                    result += "?";
                }
                current_key = ""; // Reset for the next key
            } else {
                if (in_bracket) {
                    current_key += c;
                } else {
                    result += c;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {
        {"name", "bob"}, 
        {"age", "two"}
    };
    
    string result = solution.evaluate(s, knowledge);
    
    cout << "Input string: " << s << endl;
    cout << "Evaluated string: " << result << endl;
    
    return 0;
}

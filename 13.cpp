#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();

        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int result = 0;
         
        for(int i = 0; i < n; i++){
            if(i + 1 < n && roman[s[i]] < roman[s[i + 1]]){
                result -= roman[s[i]];
            }
            else{
                result += roman[s[i]];
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    string s = "MCMXCIV"; // Example input
    int result = sol.romanToInt(s);
    cout << "The integer value of the Roman numeral is: " << result << endl;
    return 0;
}
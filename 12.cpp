#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        for(int i = 0; i < romanMap.size(); i++){
            while(num >= romanMap[i].first){
                result += romanMap[i].second;
                num -= romanMap[i].first;
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    int num = 1994; // Example input
    string result = sol.intToRoman(num);
    cout << "The Roman numeral representation is: " << result << endl;
    return 0;
}   
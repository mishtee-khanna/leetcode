#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        std::string str = std::to_string(n);
        int product = 1;
        
        sort(str.begin(), str.end());
        
        int sz = str.length();
        return (str[sz - 1] - '0') * (str[sz - 2] - '0');
    }
};

int main(){
    Solution solver;

    cout << solver.maxProduct(23) << endl;
    cout << solver.maxProduct(289493290) << endl;
    cout << solver.maxProduct(49320840) << endl;

    return 0;
}
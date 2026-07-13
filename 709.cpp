#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        string result = "";
        for(int i = 0; i < n; i++){
            result += tolower(s[i]);
        }

        return result;
    }
};

int main(){
    Solution solver;
    cout << solver.toLowerCase("I love to do coding!") << endl;

    return 0;
}
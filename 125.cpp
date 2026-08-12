#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.length() - 1;
        int left = 0;

        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};

int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama"; // Example input
    bool result = sol.isPalindrome(s);
    cout << "The string is " << (result ? "" : "not ") << "a palindrome." << endl;
    return 0;
}
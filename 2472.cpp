#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int result = 0;
        int last = -1;

        auto isPalindrome = [&](int l, int r){
            while(l < r){
                if(s[l++] != s[r--]) return false;
            }
            return true;
        };

        for(int i = k - 1; i < n; i++)
        {
            if(i - k + 1 > last && isPalindrome(i - k + 1, i)){
                result++;
                last = i;
            }
            else if(i - k > last && isPalindrome(i - k, i)){
                result++;
                last = i;
            }
        }
        return result;
    }
};

int main(){
  Solution sol;
  string s = "abcdbcda"
  int k = 3;

  cout << "Maximum number of overlapping palindromic substrings " << sol.maxPalindromes(s,k) << endl;
  return 0;
}

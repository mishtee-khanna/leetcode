#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    std::string reverseOnlyLetters(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer until it hits an English letter
            while (left < right && !std::isalpha(s[left])) {
                left++;
            }
            // Move right pointer until it hits an English letter
            while (left < right && !std::isalpha(s[right])) {
                right--;
            }

            // Swap the letters
            std::swap(s[left], s[right]);
            
            // Advance both pointers
            left++;
            right--;
        }

        return s;
    }
};

int main(){
    Solution solver;
    std::cout << solver.reverseOnlyLetters("chd-bcdhb-bcdhb-bchbh") << endl;
    std::cout << solver.reverseOnlyLetters("cudg-bcdhv-ajbxsb-jk--njsn") << endl;

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) {
            return "";
        }

        string best = "";
        
        for (int i = 0; i + k - 1 < ones.size(); ++i) {
            int start = ones[i];
            int length = ones[i + k - 1] - start + 1;
            string current = s.substr(start, length);

            if (best == "" || current.length() < best.length() || (current.length() == best.length() && current < best)) {
                best = current;
            }
        }

        return best;
    }
};

int main(){
    Solution sol;
    string s = "100011001";
    int k = 3;

    string result = sol.shortestBeautifulSubstring(s, k);
    cout << "The smallest beautiful substring is : " << result << "\n";

    return 0;
}
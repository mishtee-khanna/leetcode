#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int originalOnes = 0;
        for (char c : s) {
            if (c == '1') originalOnes++;
        }

        // Augment s with '1' at both ends
        string t = "1" + s + "1";
        
        // Parse t into alternating run lengths
        // Since t starts and ends with '1', the block sequence will be:
        // 1-block, 0-block, 1-block, 0-block, ..., 1-block
        vector<int> ones;  // lengths of '1' blocks
        vector<int> zeros; // lengths of '0' blocks

        int n = t.length();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            int len = j - i;

            if (t[i] == '1') {
                ones.push_back(len);
            } else {
                zeros.push_back(len);
            }
            i = j;
        }

        int maxGain = 0;

        // Find the maximum length of any non-adjacent '0'-block
        int maxZeroBlock = 0;
        for (int z : zeros) {
            maxZeroBlock = max(maxZeroBlock, z);
        }

        // Evaluate deleting each inner '1'-block (ones[1] to ones[ones.size() - 2])
        // Note: ones[0] and ones.back() are connected to the augmented sentinel '1's
        for (int k = 1; k < (int)ones.size() - 1; ++k) {
            int L_one = ones[k];
            int L_left = zeros[k - 1];
            int L_right = zeros[k];

            // Option A: Flip a non-adjacent '0'-block
            maxGain = max(maxGain, maxZeroBlock - L_one);

            // Option B: Flip the newly merged '0'-block (left + deleted '1' + right)
            maxGain = max(maxGain, L_left + L_right);
        }

        return originalOnes + maxGain;
    }
};

int main() {
    Solution solver;
    
    // Example test case: s = "010010"
    string s = "010010";
    cout << "Result: " << solver.maxActiveSectionsAfterTrade(s) << endl;

    return 0;
}
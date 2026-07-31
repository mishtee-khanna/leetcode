#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        int maxFreq = 0;

        // Step 1: Frequency count and track max frequency (O(N))
        for (char c : word) {
            int count = ++freq[c - 'a'];
            if (count > maxFreq) {
                maxFreq = count;
            }
        }

        // Step 2: Bucket Sort frequencies (O(26) space, max index = maxFreq)
        vector<int> bucket(maxFreq + 1, 0);
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                bucket[freq[i]]++;
            }
        }

        int totalPushes = 0;
        int lettersProcessed = 0;

        // Step 3: Iterate from highest frequency to lowest (O(26))
        for (int f = maxFreq; f > 0; --f) {
            while (bucket[f] > 0) {
                totalPushes += f * ((lettersProcessed / 8) + 1);
                lettersProcessed++;
                bucket[f]--;
            }
        }

        return totalPushes;
    }
};

int main() {
    Solution sol;
    string word = "aabbccddeeffgghhiii";

    cout << "Minimum Pushes: " << sol.minimumPushes(word) << endl;

    return 0;
}
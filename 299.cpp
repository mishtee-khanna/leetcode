#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        // Vectors to track unmatched digit frequencies (0-9)
        vector<int> secretCounts(10, 0);
        vector<int> guessCounts(10, 0);
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                // Safely track frequencies only for non-matching index positions
                secretCounts[secret[i] - '0']++;
                guessCounts[guess[i] - '0']++;
            }
        }
        
        // Intersect overlapping frequencies to prevent recycling digits
        for (int i = 0; i < 10; ++i) {
            cows += min(secretCounts[i], guessCounts[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution solver;
    
    // Test Case from your image (secret = "1123", guess = "0111")
    string secret = "1123";
    string guess = "0111";
    
    string result = solver.getHint(secret, guess);
    cout << "Result: " << result << " (Expected: 1A1B)" << endl;
    
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequency array to keep track of counts for 'b', 'a', 'l', 'o', 'n'
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        
        // Count the occurrences of each relevant character
        for (char ch : text) {
            if (ch == 'b') b++;
            else if (ch == 'a') a++;
            else if (ch == 'l') l++;
            else if (ch == 'o') o++;
            else if (ch == 'n') n++;
        }
        
        // 'l' and 'o' appear twice in "balloon", so we divide their counts by 2
        l /= 2;
        o /= 2;
        
        // The limiting factor will give us the maximum number of words
        return min({b, a, l, o, n});
    }
};

int main() {
    Solution solution;
    
    // Example test case
    string text = "loonbalxballpoon";
    cout << "Maximum instances of 'balloon': " << solution.maxNumberOfBalloons(text) << endl;
    
    return 0;
}
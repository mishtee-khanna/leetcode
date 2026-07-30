#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int pushes = 0;

        for (int i = 0; i < n; ++i) {
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};

int main() {
    Solution sol;
    
    string word = "abcde";
    cout << "Input: " << word << " -> Minimum Pushes: " << sol.minimumPushes(word) << endl;

    return 0;
}
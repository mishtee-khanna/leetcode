#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string winningPlayer(int x, int y) {
        int turns = min(x, y / 4);

        return turns % 2 ? "Alice" : "Bob";
    }
};

int main() {
    Solution sol;

    // Example usage
    int x = 5; // Number of stones in the first pile
    int y = 12; // Number of stones in the second pile

    string winner = sol.winningPlayer(x, y);
    cout << "The winning player is: " << winner << endl;

    return 0;
}
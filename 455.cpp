#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIdx = 0;
        int cookieIdx = 0;

        while (childIdx < g.size() && cookieIdx < s.size()) {
            if (s[cookieIdx] >= g[childIdx]) {
                childIdx++;
            }
            cookieIdx++;
        }

        return childIdx;
    }
};

int main() {
    Solution solver;

    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Test Case 1: " << solver.findContentChildren(g1, s1) << " (Expected: 1)" << endl;

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Test Case 2: " << solver.findContentChildren(g2, s2) << " (Expected: 2)" << endl;

    return 0;
}
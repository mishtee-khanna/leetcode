#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        
        for (int i = 0; i < n; ++i) {
            // If the number of remaining papers (including this one) is <= current citations
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        
        return 0;
    }
};

int main(){
    Solution solver;

    cout << solver.hIndex({1, 2 ,4 , 54, 67 , 87}) << endl;
    cout << solver.hIndex({1,3,1}) << endl;

    return 0;
}
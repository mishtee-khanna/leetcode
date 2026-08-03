#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> present(nums.begin(), nums.end());

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> result;
        for(int x = minVal + 1; x < maxVal; x++){
            if(present.find(x) == present.end()){
                result.push_back(x);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> nums = {1, 3, 5, 7};
    vector<int> missingElements = sol.findMissingElements(nums);

    // Print the missing elements
    for(int x : missingElements){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
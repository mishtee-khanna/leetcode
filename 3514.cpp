#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> uniqueNums = nums;
        sort(uniqueNums.begin(), uniqueNums.end());
        uniqueNums.erase(unique(uniqueNums.begin(), uniqueNums.end()), uniqueNums.end());

        int uSize = uniqueNums.size();

        vector<bool> pairXor(131072, false);
        vector<int> uniquePairs;
        
        for (int i = 0; i < uSize; ++i) {
            for (int j = i; j < uSize; ++j) {
                int x = uniqueNums[i] ^ uniqueNums[j];
                if (!pairXor[x]) {
                    pairXor[x] = true;
                    uniquePairs.push_back(x);
                }
            }
        }

        vector<bool> tripletXor(131072, false);
        int uniqueTripletCount = 0;

        for (int px : uniquePairs) {
            for (int val : uniqueNums) {
                int tx = px ^ val;
                if (!tripletXor[tx]) {
                    tripletXor[tx] = true;
                    uniqueTripletCount++;
                }
            }
        }

        return uniqueTripletCount;
    }
};

int main() {
    Solution solver;

    vector<int> nums1 = {2, 3, 1, 4};
    cout << "Test 1: " << solver.countTriplets(nums1) << " (Expected: 8)" << endl;

    vector<int> nums2 = {1, 2};
    cout << "Test 2: " << solver.countTriplets(nums2) << " (Expected: 2)" << endl;

    vector<int> nums3 = {5, 5, 5};
    cout << "Test 3: " << solver.countTriplets(nums3) << " (Expected: 1)" << endl;

    return 0;
}
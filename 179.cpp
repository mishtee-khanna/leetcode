#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }

    string largestNumber(vector<int> nums) {
        // Sort using custom comparator
        sort(nums.begin(), nums.end(), compare);

        // Edge case: if the highest number is 0, the result is "0"
        if (nums[0] == 0) {
            return "0";
        }

        string result = "";
        for (int num : nums) {
            result += to_string(num);
        }

        return result;
    }
};

int main(){
    Solution solver;

    cout << solver.largestNumber({1 , 2 ,3 , 56, 43, 7 , 9}) << endl;

    cout << solver.largestNumber({34, 56, 6 , 7 , 2 ,1 , 8}) << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            
            if (current_sum == target) {
                // Return 1-based indices as requested
                return {left + 1, right + 1};
            } else if (current_sum < target) {
                left++;  // Move to a larger value
            } else {
                right--; // Move to a smaller value
            }
        }
        
        return {}; // Fallback, though a solution is guaranteed to exist
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solver.twoSum(numbers1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "] (Expected: [1, 2])" << endl;
    
    // Test Case 2
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solver.twoSum(numbers2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "] (Expected: [1, 3])" << endl;
    
    return 0;
}
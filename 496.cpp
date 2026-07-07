#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater; // Maps: element -> its next greater element
        stack<int> st;                        // Monotonic decreasing stack
        
        // Traverse nums2 to find the next greater element for each number
        for (int num : nums2) {
            // While stack is not empty and the current number is greater than the stack's top
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num; // Set the current number as the next greater
                st.pop();                     // Remove it from the stack
            }
            st.push(num); // Push the current number onto the stack
        }
        
        // Any elements left in the stack have no next greater element, map them to -1
        while (!st.empty()) {
            next_greater[st.top()] = -1;
            st.pop();
        }
        
        // Build the result array for nums1 using our precomputed map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(next_greater[num]);
        }
        
        return ans;
    }
};
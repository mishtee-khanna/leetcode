#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        
        // Step 1: Count occurrences of each number
        for (int num : arr) {
            counts[num]++;
        }
        
        // Step 2: Insert frequencies into a set to check for duplicates
        unordered_set<int> uniqueFreqs;
        for (auto& pair : counts) {
            int frequency = pair.second;
            
            // If the frequency is already in our set, we found a duplicate frequency!
            if (uniqueFreqs.count(frequency)) {
                return false;
            }
            uniqueFreqs.insert(frequency);
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test 1: " << (solver.uniqueOccurrences(arr1) ? "true" : "false") << " (Expected: true)" << endl;
    // Explanation: 1 appears 3 times, 2 appears 2 times, 3 appears 1 time. Frequencies: {3, 2, 1} (All unique)
    
    // Test Case 2
    vector<int> arr2 = {1, 2};
    cout << "Test 2: " << (solver.uniqueOccurrences(arr2) ? "true" : "false") << " (Expected: false)" << endl;
    // Explanation: 1 appears 1 time, 2 appears 1 time. Frequencies: {1, 1} (Duplicate frequency found!)
    
    return 0;
}
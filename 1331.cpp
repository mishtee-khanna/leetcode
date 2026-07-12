#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a copy of the original array
        vector<int> sortedArr = arr;
        
        // Sort the copied array
        sort(sortedArr.begin(), sortedArr.end());
        
        // Hash map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        // Assign ranks to unique elements
        for (int num : sortedArr) {
            // If the number is not already in the map, assign the current rank
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++; // Increment rank for the next unique element
            }
        }
        
        // Replace each element in the original array with its rank
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }
        
        return arr;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> arr1 = {40, 10, 20, 30};
    solver.arrayRankTransform(arr1);
    cout << "Test 1: ";
    for (int r : arr1) cout << r << " ";
    cout << "(Expected: 4 1 2 3)" << endl;
    
    // Test Case 2: Handling duplicates
    vector<int> arr2 = {100, 100, 100};
    solver.arrayRankTransform(arr2);
    cout << "Test 2: ";
    for (int r : arr2) cout << r << " ";
    cout << "(Expected: 1 1 1)" << endl;
    
    // Test Case 3: Mixed elements
    vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    solver.arrayRankTransform(arr3);
    cout << "Test 3: ";
    for (int r : arr3) cout << r << " ";
    cout << "(Expected: 5 3 4 2 8 6 7 1 3)" << endl;
    
    return 0;
}
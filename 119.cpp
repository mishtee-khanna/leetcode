#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};

int main() {
    Solution solver;
    int rowIndex = 3;
    
    vector<int> result = solver.getRow(rowIndex);
    
    cout << "Row " << rowIndex << " of Pascal's Triangle: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl; // Expected Output: [1, 3, 3, 1]

    return 0;
}
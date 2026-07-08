#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            // A row at index i always has (i + 1) elements, initialized to 1
            vector<int> row(i + 1, 1);

            // Fill in the interior numbers (skipping the first and last element)
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Push the completed row into our triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    Solution solver;
    int numRows = 5;
    
    vector<vector<int>> result = solver.generate(numRows);

    // Printing the Pascal's Triangle
    for (int i = 0; i < result.size(); i++) {
        // Optional spacing to make it look like a triangle in terminal
        for (int space = 0; space < numRows - i; space++) {
            cout << " ";
        }
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
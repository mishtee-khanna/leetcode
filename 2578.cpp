#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        // Step 1: Convert the number to a string to easily extract digits
        string s = to_string(num);

        // Step 2: Sort the digits in ascending order
        sort(s.begin(), s.end());

        int num1 = 0;
        int num2 = 0;

        // Step 3: Alternately distribute the digits
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                num1 = num1 * 10 + (s[i] - '0');
            } else {
                num2 = num2 * 10 + (s[i] - '0');
            }
        }

        // Return the minimal possible sum
        return num1 + num2;
    }
};

int main() {
    Solution solver;

    // Example 1
    int num1 = 4325;
    cout << "Input: " << num1 << " -> Min Sum: " << solver.splitNum(num1) << endl; // Expected: 59

    // Example 2
    int num2 = 687;
    cout << "Input: " << num2 << " -> Min Sum: " << solver.splitNum(num2) << endl; // Expected: 75 (67 + 8)

    return 0;
}
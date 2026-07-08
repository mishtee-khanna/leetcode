#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        // Step 1: Extract the 4 digits into an array
        int digits[4];
        for (int i = 0; i < 4; i++) {
            digits[i] = num % 10;
            num /= 10;
        }

        // Step 2: Sort the digits in ascending order
        sort(digits, digits + 4);

        // Step 3: Combine them into two minimal 2-digit numbers
        // digits[0] and digits[1] are the smallest -> Tens place
        // digits[2] and digits[3] are the largest -> Ones place
        int new1 = digits[0] * 10 + digits[2];
        int new2 = digits[1] * 10 + digits[3];

        return new1 + new2;
    }
};

int main() {
    Solution solver;

    // Example 1: num = 2932
    // Digits sorted: 2, 2, 3, 9
    // new1 = 23, new2 = 29 -> Sum = 52
    int num1 = 2932;
    cout << "Input: " << num1 << " -> Min Sum: " << solver.minimumSum(num1) << endl;

    // Example 2: num = 4009
    // Digits sorted: 0, 0, 4, 9
    // new1 = 04, new2 = 09 -> Sum = 13
    int num2 = 4009;
    cout << "Input: " << num2 << " -> Min Sum: " << solver.minimumSum(num2) << endl;

    return 0;
}
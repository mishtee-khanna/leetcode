#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 0 || sum > 9 * num) {
            return "";
        }
        
        string result = "";
        for (int i = 0; i < num; ++i) {
            int digit = min(9, sum);
            result += to_string(digit);
            sum -= digit;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int num = 2, sum = 17;
    cout << "Result: " << sol.maxSumOfSquares(num, sum) << endl;
    return 0;
}

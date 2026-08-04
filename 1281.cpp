#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while(n != 0){
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }

        return product - sum;
    }
};

int main() {
    Solution sol;

    // Example usage
    int n = 234; // Input number

    int result = sol.subtractProductAndSum(n);
    cout << "The result of subtracting the sum from the product of digits of " << n << " is: " << result << endl;

    return 0;
}
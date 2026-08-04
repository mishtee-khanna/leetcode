#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSteps(int n) {
        int steps = 0;
        while(n != 0){
            if(n % 2 == 0){
                n /= 2;
                steps++;
            }
            else{
                n -= 1;
                steps++;
            }
        }

        return steps;

    }
};

int main() {
    Solution sol;

    // Example usage
    int n = 14; // Input number

    int steps = sol.numberOfSteps(n);
    cout << "The number of steps to reduce " << n << " to zero is: " << steps << endl;

    return 0;
}
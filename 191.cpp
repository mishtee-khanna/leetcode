#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n != 0){
            if((n & 1) == 1) count++;
            n >>= 1;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example usage
    int n = 11; // Input integer

    int weight = sol.hammingWeight(n);
    cout << "The Hamming weight of " << n << " is: " << weight << endl;

    return 0;
}
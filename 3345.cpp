#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    int smallestNumber(int n, int t) {
        while(true){
            int product = 1;
            int temp = n;

            while(temp > 0){
                product *= (temp % 10);
                temp /= 10;
            }

            if(product % t == 0) return n;
            n++;
        }
    }

};

int main(){
    Solution sol;

    int n = 10;
    int t = 5;
    cout << "Smallest number: " << sol.smallestNumber(n, t) << endl; // Should print the smallest number >= n whose product of digits is divisible by t

    return 0;
}
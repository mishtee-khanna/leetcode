#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long step = 1000;

        while(n >= step){
            total_commas +=  (n - step + 1);
            step *= 1000;
        }

        return total_commas;
    }
};

int main(){
    Solution sol;
    long long n = 100000000000;
    cout << sol.countCommas(n) << endl;
    cout << sol.countCommas(102334325483783299) << endl;

}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int K = 2 * k;

        if(N < K) return 0;

        auto power = [&](long long base, long long exp){
            long long res = 1;
            base %= MOD;
            while(exp > 0){
                if(exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        auto modInverse = [&](long long num){
            return power(num, MOD - 2);
        };

        long long ans = 1;
        for(int i = 1; i <= K; i++){
            ans = (ans * (N - i + 1)) % MOD;
            ans = (ans * modInverse(i)) % MOD;
        }
        return ans;

    }
};

int main(){
  Solution sol; 
  int n = 4, k = 2
  cout << "Number of sets of k-overlapping line segments : " << sol.numberOfSets(n,k) << endl;
  return 0;
}

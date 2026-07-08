#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        long long MOD = 1e9 + 7;
        
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<long long> sumD(n + 1, 0);
        vector<long long> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0 ? 1 : 0);
            
            if (d > 0) {
                p[i] = (p[i - 1] * 10 + d) % MOD;
            } else {
                p[i] = p[i - 1];
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            
            long long k = cntN0[r + 1] - cntN0[l];
            long long sum = sumD[r + 1] - sumD[l];
            
            long long x = (p[r + 1] - (p[l] * pow10[k]) % MOD + MOD) % MOD;
            
            long long current_ans = (x * sum) % MOD;
            answer.push_back(current_ans);
        }
        
        return answer;
    }
};

int main() {
    Solution solver;
    
    string s = "1023";
    vector<vector<int>> queries = {{0, 3}, {1, 2}, {2, 3}};
    
    vector<int> result = solver.sumAndMultiply(s, queries);
    
    for (int ans : result) {
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}
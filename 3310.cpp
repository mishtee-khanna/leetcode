#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(const auto& inv : invocations){
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        suspicious[k] = true;
        q.push(k);

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(!suspicious[v])
                {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for(const auto& inv : invocations){
            int u = inv[0], v = inv[1];
            if(!suspicious[u] && suspicious[v]){
                vector<int> all_methods(n);
                iota(all_methods.begin(), all_methods.end(), 0);
                return all_methods;
            }
        }

        vector<int> remaining;
        for(int i = 0; i < n; i++){
            if(!suspicious[i]){
                remaining.push_back(i);
            }
        }

        return remaining;

    }
};


int main(){
    Solution sol;

    int n = 5;
    int k = 1;
    vector<vector<int>> invocations = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    sol.remainingMethods(n, k, invocations);    
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int current_gas = 0;
        int start_station = 0;

        for(int i = 0; i < gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];

            current_gas += gas[i] - cost[i];

            if(current_gas < 0){
                start_station = i + 1;
                current_gas = 0;
            }
        }

        if(total_gas < total_cost) return -1;
        return start_station;
    }
};

int main(){
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5}; // Example input
    vector<int> cost = {3, 4, 5, 1, 2}; // Example input
    int result = sol.canCompleteCircuit(gas, cost);
    cout << "The starting gas station index is: " << result << endl;
    return 0;
}
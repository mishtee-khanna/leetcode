#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    int turnedOn = 1;
    
    vector<string> times = solver.readBinaryWatch(turnedOn);
    
    cout << "Possible times for turnedOn = " << turnedOn << ":" << endl;
    for (const string& time : times) {
        cout << time << " ";
    }
    cout << endl;
    
    // Expected Output for 1: 1:00 2:00 4:00 8:00 0:01 0:02 0:04 0:08 0:16 0:32

    return 0;
}
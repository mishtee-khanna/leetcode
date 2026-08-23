#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.length();
        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;

        for(int i = 0; i < n / 2; i++){
            if(nums[i] == '?'){
                q1++;
            }
            else{
                s1 += nums[i] - '0';
            }
        }

        for(int i = n / 2; i < n; i++){
            if(nums[i] == '?'){
                q2++;
            }
            else{
                s2 += nums[i] - '0';
            }
        }
        
        if((q1 + q2) % 2 != 0) return true;

        return (s1 - s2) != (q2 - q1) / 2 * 9;
    }
};

int main(){
    Solution sol;

    string string1 = "123456";
    cout << "Alice wins ? " << sol.sumGame(string1) << endl;

    string string2 = "12341234";
    cout << "Alice wins ?" << sol.sumGame(string2) << endl;

    return 0;
}
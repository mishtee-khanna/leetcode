#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);

        int sum = 0, left = 0;
        int minLen = INT_MAX;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++){
            sum += arr[right];

            while(sum > target && left <= right){
                sum -= arr[left];
                left++;
            }

            if(sum == target){
                int curr = right - left + 1;

                if(left > 0 && best[left - 1] != INT_MAX ){
                    ans = min(ans, curr + best[left - 1]);
                }
                minLen = min(minLen, curr);
            }
            best[right] = minLen;

        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
  Solution sol;
  vector<int> arr = {1 , 2 , 3 , 4 , 5};
  int target = 3;
  cout << sol.minSumOfLengths(arr, target) << endl;
  return 0;
}

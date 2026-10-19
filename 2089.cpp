class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessCount = 0;
        int targetCount = 0;

        for(int num : nums){
            if(num < target) lessCount++;
            else if(num == target) targetCount++;
        }

        vector<int> result;
        for(int i = 0; i < targetCount; i++){
            result.push_back(lessCount + i);
        }

        return result;
    }
};

int main(){
  Solution sol;
  
  vector<int> nums = { 1 , 2 , 2 , 2 , 3 , 3 , 4};
  int target = 2;
  vector<int> result = sol.targetIndices(nums, target);
  for( int num : result){
    cout << num << " ";
  }
  return 0;
}

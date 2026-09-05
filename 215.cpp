#include<bits/stdc++.h>

using namespace std;

int kthLargest(vector<int> nums, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < nums.size(); i++){
        minHeap.push(nums[i]);

        if(minHeap.size() > k) minHeap.pop();
    }

    return minHeap.top();
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    int k = 3;

    cout << "Kth largest element in the array where k is " << k << " is " << kthLargest(arr, k) << endl;
    return 0;
}
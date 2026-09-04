#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int target, int left, int right){
    if(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) return mid;

        if(target < arr[mid]){
            return binarySearch(arr, target, left, mid - 1);
        }
        else{
            return binarySearch(arr, target, mid + 1, right);
        }

    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 50;
    int target2 = 5;
    cout << binarySearch(arr, target, 0, arr.size() - 1) << endl;
    cout << binarySearch(arr2, target2, 0, arr2.size() - 1) << endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &arr, int n){
    if(n == 1) return true;

    if(arr[n - 1] < arr[n - 2]) return false;

    return isSorted(arr, n - 1);
}

int main(){
    vector<int> arr = {1  , 9 , 4 , 5 , 6 , 7 , 8 , 9 , 10}; 
    int n = arr.size();

    cout << isSorted(arr, n) << endl;

    return 0;
}
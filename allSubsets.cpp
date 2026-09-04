#include<bits/stdc++.h>

using namespace std;

bool isSorted(vector<int> &arr, int n){
    if(n == 1) return true;

    if(arr[n - 1] < arr[n - 2]) return false;

    return isSorted(arr, n - 1);
}


void printSubSets(vector<int> &arr, vector<int> &subset, int i){
    if(i == arr.size()){
        for(int j = 0; j < subset.size(); j++){
            cout << subset[j] << " ";
        }
        cout << endl;
        return;
    }
    subset.push_back(arr[i]);
    printSubSets(arr, subset, i + 1);
    subset.pop_back();
    printSubSets(arr, subset, i + 1);
}
int main(){
    vector<int> arr = {1  , 9 , 4 , 5 , 6 , 7 , 8 , 9 , 10}; 
    int n = arr.size();

    vector<int> arr2 = {1, 2, 3};
    vector<int> ans;

    printSubSets(arr2, ans, 0);


    return 0;
}
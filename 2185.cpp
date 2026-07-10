#include<bits/stdc++.h>
using namespace std;

int prefixCount(string s, vector<string>& words){
    int count = 0;

    for(const string& word : words){
        if(s.find(word) == 0){
            count++;
        }
    }

    return count;
}

int main(){
    string s = "abc";
    vector<string> words = {"a", "b", "c", "ab", "bc", "abc"};
    cout << prefixCount(s, words) << endl;
    return 0;
}
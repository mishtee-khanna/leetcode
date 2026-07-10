#include<bits/stdc++.h>
using namespace std;

bool repeatedSubStringPattern(string s){
    return (s + s).find(s, 1) < s.length();
}

int main(){
    string s = "abab";
    cout << repeatedSubStringPattern(s) << endl;
    return 0;
}


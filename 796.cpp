#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal){
    if(s.length() != goal.length()) return false;

    return (s + s).find(s) != string::npos;
}

int main(){
    string s = "abcde";
    string goal = "edcba";
    cout << rotateString(s, goal) << endl;
    return 0;
}
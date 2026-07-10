#include<bits/stdc++.h>
using namespace std;

int maxRepeating(string sequence, string word){
    int k = 0;
    string repeatedWord = word;

    while(sequence.find(repeatedWord) != string::npos){
        k++;
        repeatedWord += word;
    }

    return k;
}

int main(){
    string sequence = "ababc";
    string word = "ab";
    cout << maxRepeating(sequence, word) << endl;
    return 0;
}
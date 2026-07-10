#include<bits/stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string>& words){
    vector<string> result;

    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.size(); j++){
            if(i != j && words[j].find(words[i]) != string::npos){
                result.push_back(words[i]);
                break;
            }
        }
    }
    return result;
}

int main(){
    vector<string> words = {"mass", "as", "hero", "superhero"};
    vector<string> result = stringMatching(words);

    for(const string& word : result){
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
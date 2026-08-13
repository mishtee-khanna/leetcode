#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }
            else if(token == ".."){
                if(!st.empty()) st.pop_back();
            }
            else st.push_back(token);
        }

        string result = "";
        for(const string& dir : st){
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;

    }
};

int main(){
    Solution sol;
    string path = "/a/./b/../../c/"; // Example input
    string result = sol.simplifyPath(path);
    cout << "The simplified path is: " << result << endl;

    string path2 = "/../"; // Another example input
    string result2 = sol.simplifyPath(path2);
    cout << "The simplified path is: " << result2 << endl;

    string path3 = "/home//foo/"; // Another example input
    string result3 = sol.simplifyPath(path3);
    cout << "The simplified path is: " << result3 << endl;

    string path4 = "/a//b"; 
    string result4 = sol.simplifyPath(path4);   
    cout << "The simplified path is: " << result4 << endl;

    string path5 = "/a/../../b/../c//.//";
    string result5 = sol.simplifyPath(path5);
    cout << "The simplified path is: " << result5 << endl;
    return 0;
}
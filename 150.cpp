#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                if(token == "+"){
                    st.push(num1 + num2);
                }
                else if(token == "-"){
                    st.push(num1 - num2);
                }
                else if(token == "*"){
                    st.push(num1 * num2);
                }
                else if(token == "/"){
                    st.push(num1 / num2);
                }
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main(){
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"}; // Example input
    int result = sol.evalRPN(tokens);
    cout << "The result of the RPN expression is: " << result << endl;

    vector<string> tokens2 = {"4", "13", "5", "/", "+"}; // Another example input
    int result2 = sol.evalRPN(tokens2);
    cout << "The result of the RPN expression is: " << result2 << endl;

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}; // Another example input
    int result3 = sol.evalRPN(tokens3);
    cout << "The result of the RPN expression is: " << result3 << endl;

    return 0;
}
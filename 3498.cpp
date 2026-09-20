#include<bita/atdc++.h>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            int stringPos = i + 1;
            int reversedPos = 26 - (s[i] - 'a');

            total += stringPos * reversedPos;
        }
        return total;
    }
};

int main(){
  Solution sol;
  string s = "abc";
  cout << "Reverse Degree : " << sol.reverseDegree(s);
  return 0;
}

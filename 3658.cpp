#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int a, int b){
        if(b == 0) return a;
        else return(b, a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        if(n == 1) return 1;
        if(n <= 0) return 0; 
        int sumOdd = 0;
        int sumEven = 0;
        for(int i = 1; i <= 2 * n; i++){
            if(i % 2 == 0){
                sumEven += i;
            }
            else sumOdd += i;
        }

        return gcd(sumEven, sumOdd);
    }
};


int main(){
    Solution solver;

    cout << solver.gcdOfOddEvenSums(4) << endl;
    cout << solver.gcdOfOddEvenSums(6) << endl;

    return 0;
}
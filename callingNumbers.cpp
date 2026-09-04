#include<bits/stdc++.h>

using namespace std;

void printNumbers(int n, int m){
    if(n == m){
        cout << n << endl;
    }
        
    else{
        cout << n << endl;
        printNumbers(n + 1, m);
    }
}
void print(int n){
    if(n == 1) cout << n << endl;
    else{
        cout << n << endl;
        print(n - 1);
    }

}
int main(){

    printNumbers(1, 10);
    cout << "\n";

    print(5);
    return 0;
}
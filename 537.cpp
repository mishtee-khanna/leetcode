#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;
        char plus, i;
        
        stringstream ss1(num1);
        ss1 >> a >> plus >> b >> i;
        
        stringstream ss2(num2);
        ss2 >> c >> plus >> d >> i;
        
        int realPart = a * c - b * d;
        int imagPart = a * d + b * c;
        
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
};

int main() {
    Solution solver;

    // Test Case 1: "1+1i" * "1+1i"
    // (1 + i)(1 + i) = 1 + i + i + i^2 = 1 + 2i - 1 = 0 + 2i
    string num1 = "1+1i";
    string num2 = "1+1i";
    cout << "Test 1: " << solver.complexNumberMultiply(num1, num2) << " (Expected: 0+2i)" << endl;

    // Test Case 2: "1+-1i" * "1+-1i"
    // (1 - i)(1 - i) = 1 - i - i + i^2 = 1 - 2i - 1 = 0+-2i
    string num3 = "1+-1i";
    string num4 = "1+-1i";
    cout << "Test 2: " << solver.complexNumberMultiply(num3, num4) << " (Expected: 0+-2i)" << endl;

    return 0;
}
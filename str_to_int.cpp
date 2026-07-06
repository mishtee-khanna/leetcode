#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(const string& s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
            int digit = s[i] - '0';

            // Pre-check overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++; 
        }

        return sign * result;
    }
};

// Main function to test the code in VS Code
int main() {
    Solution solver;
    
    // Test cases
    string test1 = "   -42";
    string test2 = "4193 with words";
    string test3 = "words and 987";
    string test4 = "-91283472332"; // Out of 32-bit bound

    cout << "Test 1 (\"" << test1 << "\"): " << solver.myAtoi(test1) << " (Expected: -42)\n";
    cout << "Test 2 (\"" << test2 << "\"): " << solver.myAtoi(test2) << " (Expected: 4193)\n";
    cout << "Test 3 (\"" << test3 << "\"): " << solver.myAtoi(test3) << " (Expected: 0)\n";
    cout << "Test 4 (\"" << test4 << "\"): " << solver.myAtoi(test4) << " (Expected: " << INT_MIN << ")\n";

    return 0;
}
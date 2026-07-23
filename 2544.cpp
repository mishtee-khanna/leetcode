#include <iostream>
#include <string>

using namespace std;

int alternateDigitSum(int n) {
    string s = to_string(n);
    int sum = 0;
    int sign = 1; // First digit is positive

    for (char c : s) {
        sum += sign * (c - '0');
        sign *= -1; // Alternate sign
    }

    return sum;
}

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Alternate Digit Sum: " << alternateDigitSum(n) << endl;

    return 0;
}

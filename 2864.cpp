#include <iostream>
#include <string>

using namespace std;

string maximumOddBinaryNumber(string s) {
    int ones = 0, zeros = 0;

    for (char c : s) {
        if (c == '1')
            ones++;
        else
            zeros++;
    }

    string result = "";

    // Put all but one '1' at the front
    result.append(ones - 1, '1');

    // Put all '0's in the middle
    result.append(zeros, '0');

    // Put the last '1' at the end
    result.push_back('1');

    return result;
}

int main() {
    string s;

    cout << "Enter a binary string: ";
    cin >> s;

    cout << "Maximum odd binary number: " << maximumOddBinaryNumber(s) << endl;

    return 0;
}

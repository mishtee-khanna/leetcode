#include <iostream>
using namespace std;

string compressString(string s) {
    string result = "";
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        result += s[i];

        if (count > 1)
            result += to_string(count);
    }

    return result;
}

int main() {
    string s = "abbbcccc";

    cout << compressString(s);

    return 0;
}


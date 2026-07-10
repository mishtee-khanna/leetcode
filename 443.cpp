#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  // position where we write compressed characters
        int i = 0;      // position for scanning

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // Count consecutive characters
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write the character
            chars[write++] = ch;

            // Write the count if greater than 1
            if (count > 1) {
                string cnt = to_string(count);

                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution solution;
    int newLength = solution.compress(chars);

    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}
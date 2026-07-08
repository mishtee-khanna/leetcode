#include <iostream>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        // Using standard fixed-size arrays for letter frequencies (a-z)
        array<int, 26> s_count = {0};
        array<int, 26> t_count = {0};

        for (int i = 0; i < s.length(); i++) {
            s_count[s[i] - 'a']++;
            t_count[t[i] - 'a']++;
        }

        // std::array supports direct equality comparison
        return s_count == t_count;
    }
};

int main() {
    Solution solver;

    string s = "anagram";
    string t = "nagaram";

    if (solver.isAnagram(s, t)) {
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s << "\" and \"" << t << "\" are NOT anagrams." << endl;
    }

    return 0;
}
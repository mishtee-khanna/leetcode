#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

int main() {
    Solution solver;

    string s1 = "ab#c", t1 = "ad#c";
    cout << "Test 1: " << (solver.backspaceCompare(s1, t1) ? "true" : "false") << " (Expected: true)" << endl;

    string s2 = "ab##", t2 = "c#d#";
    cout << "Test 2: " << (solver.backspaceCompare(s2, t2) ? "true" : "false") << " (Expected: true)" << endl;

    string s3 = "a#c", t3 = "b";
    cout << "Test 3: " << (solver.backspaceCompare(s3, t3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}
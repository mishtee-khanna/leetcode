#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.length());
        int depth = 0;
        
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                result[i] = depth % 2;
                depth++;
            } else {
                depth--;
                result[i] = depth % 2;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string seq = "(()())";
    vector<int> result = solution.maxDepthAfterSplit(seq);
    
    cout << "Input: " << seq << "\nOutput: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]\n";

    return 0;
}

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        
        int sum = 0;
        // If current node is within range, add its value
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        
        // Only branch left if the current value could have smaller valid numbers
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        
        // Only branch right if the current value could have larger valid numbers
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        
        return sum;
    }
};

int main() {
    Solution solver;
    // Construct BST:
    //      10
    //     /  \
    //    5    15
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    cout << "Range Sum (7 to 15): " << solver.rangeSumBST(root, 7, 15) << " (Expected: 25)" << endl;

    delete root->left; delete root->right; delete root;
    return 0;
}
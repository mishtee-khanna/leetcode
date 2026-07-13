#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Using long long parameters to handle potential INT_MIN and INT_MAX node value edge cases safely
    bool validate(TreeNode* root, long long low, long long high) {
        if (root == nullptr) return true;
        
        // Current node value must strictly stay within its inherited range boundaries
        if (root->val <= low || root->val >= high) return false;
        
        // Left child must be smaller than root->val
        // Right child must be larger than root->val
        return validate(root->left, low, root->val) && validate(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution solver;
    cout << boolalpha;

    // Construct valid BST
    TreeNode* validRoot = new TreeNode(2);
    validRoot->left = new TreeNode(1);
    validRoot->right = new TreeNode(3);
    cout << "Is Valid BST: " << solver.isValidBST(validRoot) << " (Expected: true)" << endl;

    // Construct invalid BST (5 is right child of 2, but 1 is left child of 5 - which is invalid because 1 < 2)
    TreeNode* invalidRoot = new TreeNode(2);
    invalidRoot->left = new TreeNode(4); 
    invalidRoot->right = new TreeNode(3);
    cout << "Is Valid BST: " << solver.isValidBST(invalidRoot) << " (Expected: false)" << endl;

    delete validRoot->left; delete validRoot->right; delete validRoot;
    delete invalidRoot->left; delete invalidRoot->right; delete invalidRoot;
    return 0;
}
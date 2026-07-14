#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};

int main() {
    Solution solver;
    cout << boolalpha; // Prints true/false instead of 1/0

    /*
       Let's construct a symmetric tree:
             1
            / \
           2   2
          / \ / \
         3  4 4  3
    */
    TreeNode* symmetricRoot = new TreeNode(1);
    symmetricRoot->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    symmetricRoot->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    cout << "Is Tree Symmetric: " << solver.isSymmetric(symmetricRoot) << " (Expected: true)" << endl;

    /*
       Let's construct an asymmetric tree:
             1
            / \
           2   2
            \   \
             3   3
    */
    TreeNode* asymmetricRoot = new TreeNode(1);
    asymmetricRoot->left = new TreeNode(2, nullptr, new TreeNode(3));
    asymmetricRoot->right = new TreeNode(2, nullptr, new TreeNode(3));

    cout << "Is Tree Symmetric: " << solver.isSymmetric(asymmetricRoot) << " (Expected: false)" << endl;

    // Clean up memory (Symmetric Tree)
    delete symmetricRoot->left->left; delete symmetricRoot->left->right;
    delete symmetricRoot->right->left; delete symmetricRoot->right->right;
    delete symmetricRoot->left; delete symmetricRoot->right; delete symmetricRoot;

    // Clean up memory (Asymmetric Tree)
    delete asymmetricRoot->left->right; delete asymmetricRoot->right->right;
    delete asymmetricRoot->left; delete asymmetricRoot->right; delete asymmetricRoot;

    return 0;
}
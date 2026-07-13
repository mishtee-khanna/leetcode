#include <iostream>
#include <algorithm>

using namespace std; // Applied per your VS Code workflow preference

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
public:
    int maxDepth(TreeNode* root) {
        // Base Case: An empty tree has a depth of 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursive step: Get the depth of both subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The maximum depth of the current node is 1 plus the larger of the two sub-depths
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    Solution solver;

    /*
       Let's construct a sample binary tree:
             3
            / \
           9  20
             /  \
            15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the solver
    int depth = solver.maxDepth(root);
    cout << "Maximum Depth of the Tree: " << depth << " (Expected: 3)" << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
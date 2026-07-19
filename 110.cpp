#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std; 

// Standard LeetCode definition for a binary tree node.
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
    // Helper function that calculates height and short-circuits via reference
    int calculateHeight(TreeNode* root, bool& balanced) {
        // Instant escape if node is null OR if an imbalance was already flagged
        if (root == nullptr || !balanced) {
            return 0;
        }
        
        int leftHeight = calculateHeight(root->left, balanced);
        int rightHeight = calculateHeight(root->right, balanced);
        
        // Check balance condition at the current node
        if (abs(leftHeight - rightHeight) > 1) {
            balanced = false;
        }
        
        // Return actual height to the parent call
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        calculateHeight(root, balanced);
        return balanced;
    }
};

int main() {
    Solution solver;

    // Test Case: Building a balanced binary tree
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Run the solver
    if (solver.isBalanced(root)) {
        cout << "Test Result: The tree is height-balanced! (Expected)" << endl;
    } else {
        cout << "Test Result: The tree is NOT height-balanced." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
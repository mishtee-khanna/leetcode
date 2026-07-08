#include <iostream>
#include <algorithm>

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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base Case 1: Empty tree/node
        if (root == nullptr) {
            return false;
        }

        // Base Case 2: Leaf node check
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        // Recursive Step: Subtract current node's value and look down both paths
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};

int main() {
    Solution solver;

    // Creating a sample tree:
    //       5
    //      / \
    //     4   8
    //    /
    //   11
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);

    int target = 20; // Path: 5 -> 4 -> 11 (Sum = 20)

    if (solver.hasPathSum(root, target)) {
        cout << "True: A root-to-leaf path with sum " << target << " exists." << endl;
    } else {
        cout << "False: No such path exists." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
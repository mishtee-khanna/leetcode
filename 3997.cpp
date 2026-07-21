#include <iostream>
#include <algorithm>
#include <climits>

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
    int dominantCount = 0;

    int dfs(TreeNode* root) {
        if (!root) return INT_MIN;

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        int currentMax = max({root->val, leftMax, rightMax});

        if (root->val == currentMax) {
            dominantCount++;
        }

        return currentMax;
    }

public:
    int countDominantNodes(TreeNode* root) {
        dominantCount = 0;
        dfs(root);
        return dominantCount;
    }
};

int main() {
    Solution solver;

    /*
         Constructing Tree:
               5
             /   \
            3     4
           / \
          2   1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);

    cout << "Dominant Nodes Count: " << solver.countDominantNodes(root) << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
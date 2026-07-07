#include <iostream>
#include <vector>

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
    void postorder(TreeNode* root, vector<int>& result) {
        // Base case: if the node is null, return
        if (root == nullptr) {
            return;
        }
        
        postorder(root->left, result);  // Traverse left subtree
        postorder(root->right, result); // Traverse right subtree
        result.push_back(root->val);    // Visit root
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
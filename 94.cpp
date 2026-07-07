#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void inorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        inorderHelper(root->left, result);  // Traverse Left
        result.push_back(root->val);        // Visit Root
        inorderHelper(root->right, result); // Traverse Right
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};

// Helper function to insert nodes to form a Binary Search Tree
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = nullptr;

    // Creating a sample BST
    //        4
    //       / \
    //      2   6
    //     / \   \
    //    1   3   7
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 7);

    vector<int> ordered_elements = solution.inorderTraversal(root);

    cout << "Inorder Traversal (Sorted Output for BST): ";
    for (int val : ordered_elements) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
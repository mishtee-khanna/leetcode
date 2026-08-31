#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {

private:
    void traverse(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;

        // Root
        result.push_back(root->val);

        // Left
        traverse(root->left, result);

        // Right
        traverse(root->right, result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        traverse(root, result);

        return result;
    }
};

int main() {

    // Creating the binary tree:
    //
    //        1
    //         \
    //          2
    //         /
    //        3
    //
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Create Solution object
    Solution solution;

    // Get preorder traversal
    vector<int> result = solution.preorderTraversal(root);

    // Print result
    cout << "Preorder Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
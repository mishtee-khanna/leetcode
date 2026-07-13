#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr; // Tracks the previously visited node in-order
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        
        // Process current node
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root; // Move pointer forward
        
        inorder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        minDiff = INT_MAX;
        prev = nullptr;
        inorder(root);
        return minDiff;
    }
};

int main() {
    Solution solver;
    // Construct BST:
    //      4
    //     / \
    //    2   6
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    cout << "Min Distance: " << solver.minDiffInBST(root) << " (Expected: 2)" << endl;

    delete root->left; delete root->right; delete root;
    return 0;
}
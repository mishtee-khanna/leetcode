#include <iostream>
#include <vector>
#include <queue>

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
private:
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
};

// Helper function to print tree level-by-level (Breadth-First Search)
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Helper function to clean up allocated tree nodes
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution solver;
    vector<int> nums = {-10, -3, 0, 5, 9};

    cout << "Input Sorted Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    TreeNode* root = solver.sortedArrayToBST(nums);

    cout << "BST Level-Order Output: ";
    printLevelOrder(root); 
    // Expected visual shape structure matching a valid balanced tree setup

    freeTree(root);
    return 0;
}
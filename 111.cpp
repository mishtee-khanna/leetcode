#include <iostream>
#include <queue>
#include <algorithm>

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
public:
    int minDepth(TreeNode* root) {
        // Base case: empty tree has a depth of 0
        if (root == nullptr) {
            return 0;
        }
        
        // Queue stores pairs of {current_node, current_depth}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            // Short-circuit: The first leaf node encountered is the closest leaf node
            if (curr->left == nullptr && curr->right == nullptr) {
                return depth;
            }
            
            // Traverse down to the next level
            if (curr->left != nullptr) {
                q.push({curr->left, depth + 1});
            }
            if (curr->right != nullptr) {
                q.push({curr->right, depth + 1});
            }
        }
        
        return 0;
    }
};

int main() {
    Solution solver;

    // Test Case: Creating an unbalanced tree structure
    //        3
    //       / \
    //      9   20
    //         /  \
    //        15   7
    // Minimum depth path goes from 3 -> 9 (Length: 2 nodes)
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Minimum Depth: " << solver.minDepth(root) << " (Expected: 2)" << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
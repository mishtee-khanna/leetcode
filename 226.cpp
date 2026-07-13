#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        // Base Case: If the node is empty, there is nothing to invert
        if (root == nullptr) {
            return nullptr;
        }
        
        // Swap the left and right child pointers of the current node
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert the subtrees down the line
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

// Helper function to print the tree level by level (BFS) to verify the result
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (curr != nullptr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    Solution solver;

    /*
       Original Tree setup:
             4
            / \
           2   7
          / \ / \
         1  3 6  9
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree Level-Order: ";
    printLevelOrder(root);

    // Invert the tree
    root = solver.invertTree(root);

    /*
       Expected Inverted Tree output layout:
             4
            / \
           7   2
          / \ / \
         9  6 3  1
    */
    cout << "Inverted Tree Level-Order: ";
    printLevelOrder(root);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
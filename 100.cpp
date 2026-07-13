#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case 1: Both nodes are null, so they match perfectly
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base Case 2: One node is null but the other isn't, so they structurally mismatch
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Base Case 3: The data values stored inside the current nodes mismatch
        if (p->val != q->val) {
            return false;
        }
        
        // Recursive Step: Check if both left and right subtrees match identically
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution solver;
    cout << boolalpha; // Formats terminal output to print true/false instead of 1/0

    // --- TREE 1 ---
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    // --- TREE 2 (Matches Tree 1) ---
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "Test Case 1: " << solver.isSameTree(p1, q1) << " (Expected: true)" << endl;

    // --- TREE 3 (Structural Mismatch) ---
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2); // Left heavy structure

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2); // Right heavy structure

    cout << "Test Case 2: " << solver.isSameTree(p2, q2) << " (Expected: false)" << endl;

    // Memory clean up
    delete p1->left; delete p1->right; delete p1;
    delete q1->left; delete q1->right; delete q1;
    delete p2->left; delete p2;
    delete q2->right; delete q2;

    return 0;
}
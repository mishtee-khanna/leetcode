#include <iostream>
#include <vector>

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
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);
            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* currentRoot = new TreeNode(i);
                    currentRoot->left = left;
                    currentRoot->right = right;
                    allTrees.push_back(currentRoot);
                }
            }
        }
        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesHelper(1, n);
    }
};

// Helper function to print tree structure inline (Preorder: Root -> Left -> Right)
void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        cout << "null ";
        return;
    }
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

// Memory cleanup utility
void freeTree(TreeNode* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    Solution solver;
    int n = 3;
    vector<TreeNode*> result = solver.generateTrees(n);

    cout << "Total unique BSTs generated for n = " << n << ": " << result.size() << "\n\n";
    
    for (int i = 0; i < result.size(); ++i) {
        cout << "Tree " << i + 1 << " (Preorder layout): ";
        printPreorder(result[i]);
        cout << "\n";
    }

    // Clean up memory
    for (TreeNode* root : result) {
        freeTree(root);
    }

    return 0;
}
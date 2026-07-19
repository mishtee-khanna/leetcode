#include <iostream>
#include <vector>
#include <string>

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
private:
    void constructPaths(TreeNode* root, string path, vector<string>& answer) {
        if (root == nullptr) return;
        
        path += to_string(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            answer.push_back(path);
            return;
        }
        
        if (root->left != nullptr) {
            constructPaths(root->left, path + "->", answer);
        }
        if (root->right != nullptr) {
            constructPaths(root->right, path + "->", answer);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        constructPaths(root, "", answer);
        return answer;
    }
};

int main() {
    Solution solver;

    // Test Case:
    //        1
    //       / \
    //      2   3
    //       \
    //        5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> result = solver.binaryTreePaths(root);

    cout << "Root-to-Leaf Paths:" << endl;
    for (const string& path : result) {
        cout << path << endl; 
        // Expected Output:
        // "1->2->5"
        // "1->3"
    }

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
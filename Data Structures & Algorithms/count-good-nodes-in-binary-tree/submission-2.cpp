/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    int good = 0; 
    void dfs(TreeNode* node, int maxVal) {
        if (!node) return;
        if (node->val >= maxVal) ++good;
        if (node->left) dfs(node->left, std::max(maxVal, node->val));
        if (node->right) dfs(node->right, std::max(maxVal, node->val));
    }

public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return good;
    }   
};

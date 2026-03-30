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
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;

        int good = (node->val >= maxVal) ? 1 : 0;
        if (node->left)  good += dfs(node->left, std::max(maxVal, node->val));
        if (node->right) good += dfs(node->right, std::max(maxVal, node->val));

        return good;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }   
};

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
    int ans = INT_MIN;

    int getMax(TreeNode* node) {
        if (!node) return 0;
        int left  = getMax(node->left);  
        int right = getMax(node->right);
        int path = node->val + std::max(left, right);
        return std::max(0, path); // is it better to take the path or not  
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        int left  = getMax(root->left);
        int right = getMax(root->right);

        ans = std::max(ans, root->val + right + left);

        dfs(root->left);
        dfs(root->right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

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

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = std::max(0, dfs(node->left));
        int right = std::max(0, dfs(node->right));

        ans = std::max(ans, node->val + left + right);

        return node->val + std::max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

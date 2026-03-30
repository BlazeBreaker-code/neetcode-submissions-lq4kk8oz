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
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int leftMax  = std::max(dfs(root->left, ans), 0);
        int rightMax = std::max(dfs(root->right, ans), 0);

        ans = std::max(ans, root->val + leftMax + rightMax);
        return root->val + std::max(leftMax, rightMax);
    }

public:
    int maxPathSum(TreeNode* root) {
        if (!root) return INT_MIN;
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
};

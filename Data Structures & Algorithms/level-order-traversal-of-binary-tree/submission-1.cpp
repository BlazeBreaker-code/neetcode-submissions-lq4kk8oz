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
    vector<vector<int>> ans;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (ans.size() == depth) {
            ans.push_back(vector<int>());
        }

        ans[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // we want to dive deep for each branch adding to the the list at each level
        dfs(root, 0);
        return ans;
    }
};

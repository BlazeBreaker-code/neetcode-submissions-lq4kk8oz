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
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int good = 0; 
        std::queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while (!q.empty()) {
            auto [node, maxVal] = q.front(); q.pop();

            if (node->val >= maxVal) ++good;
            if (node->left) q.push({ node->left, std::max(maxVal, node->val)});
            if (node->right) q.push({ node->right, std::max(maxVal, node->val)});
        }

        return good;
    }
};

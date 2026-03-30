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

        std::queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        int good = 0;
        while (!q.empty()) {
            auto [node, maxVal] = q.front(); q.pop();
            if (node->val >= maxVal) ++good;

            if (node->left)  q.push({node->left, std::max(node->val, maxVal)});
            if (node->right) q.push({node->right, std::max(node->val, maxVal)});
        }

        return good;
    }
};

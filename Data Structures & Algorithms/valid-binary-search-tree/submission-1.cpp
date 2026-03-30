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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        struct Item {
            TreeNode* node;
            long long left; 
            long long right;
        };

        std::queue<Item> q;
        q.push({root, LLONG_MIN, LLONG_MAX});

        while (!q.empty()) {
            auto [node, left, right] = q.front(); q.pop();

            if (left >= node->val || node->val >= right) return false; 
            if (node->left) q.push({node->left, left, node->val});
            if (node->right) q.push({node->right, node->val, right});
        }

        return true;
    }
};

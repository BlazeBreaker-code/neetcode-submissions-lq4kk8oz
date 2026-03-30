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
    bool isBalanced(TreeNode* root) {
        // not balanced if the more the lengths of the ends are more than 1
        return balanced(root) != -1;
    }

    int balanced(TreeNode* node) {
        if (!node) return 0;

        int left = balanced(node->left);
        if (left == -1) return -1;

        int right = balanced(node->right);
        if (right == -1) return -1;

        if (std::abs(right - left) > 1) return -1;

        return std::max(left, right) + 1;
    }
};

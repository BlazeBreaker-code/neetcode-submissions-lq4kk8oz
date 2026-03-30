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
        return balanced(root) != -1;
    }

private:
    int balanced(TreeNode* node) {
        if (!node) return 0;

        int leftH  = balanced(node->left);
        if (leftH == -1) return -1;

        int rightH = balanced(node->right);
        if (rightH == -1) return -1;

        if (std::abs(rightH - leftH) > 1) return -1;

        return std::max(leftH, rightH) + 1;
    }
};

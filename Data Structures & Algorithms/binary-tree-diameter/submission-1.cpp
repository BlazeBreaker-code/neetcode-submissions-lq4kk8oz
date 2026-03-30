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
    int maxDiameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxDiameter;
    }

    int diameter(TreeNode* node) { 
        if (!node) return 0;

        int left  = diameter(node->left);
        int right = diameter(node->right);

        maxDiameter = std::max(maxDiameter, left + right);

        return std::max(left, right) + 1;
    }
};

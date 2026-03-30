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
    int count = 0;
    int ans = -1;

    void findKth(TreeNode* node, int k) {
        if (!node) return;

        findKth(node->left, k);

        ++count;
        if (count == k) {
            ans = node->val;
            return;
        }

        findKth(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        findKth(root, k);
        return ans;
    }
};

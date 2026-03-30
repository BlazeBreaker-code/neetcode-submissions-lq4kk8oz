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
    int ans = -1;
    int count = 0;

    void findKth(TreeNode* node, int k) {
        if (!node) return;

        findKth(node->left, k); // 3 2 

        ++count; // first lowest 
        if (count == k) {
            ans = node->val;
            return;
        }

        findKth(node->right, k); // no right
    } 

public:
    int kthSmallest(TreeNode* root, int k) {
        findKth(root, k);
        return ans;
    }
};

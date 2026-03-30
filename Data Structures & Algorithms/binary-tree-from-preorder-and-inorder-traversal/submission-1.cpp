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
    int preIdx = 0; 
    int inIdx = 0; 

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        // in order means 1,2,3,4
        // preorder means 2,1,3,4
        if (preIdx >= preorder.size()) return nullptr;

        if (inorder[inIdx] == limit) {
            ++inIdx;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left  = dfs(preorder, inorder, root->val); 
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};

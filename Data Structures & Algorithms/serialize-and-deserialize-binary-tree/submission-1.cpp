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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> ans;
        string curr;

        for (char c : data) {
            if (c == ',') {
                ans.push_back(curr); 
                curr.clear();
            } else {
                curr += c;
            }
        }

        ans.push_back(curr);

        int i = 0;
        return build(ans, i);
    }

    TreeNode* build(vector<string>& ans, int& i) {
        if (ans[i] == "N") {
            ++i;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(ans[i++]));
        node->left  = build(ans, i);
        node->right = build(ans, i);

        return node;
    }   
};

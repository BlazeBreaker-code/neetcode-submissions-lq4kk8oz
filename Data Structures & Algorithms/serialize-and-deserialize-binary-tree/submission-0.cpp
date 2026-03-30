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
        vector<string> vals;
        string curr;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(curr);
                curr.clear();
            } else {
                curr += c;
            }
        }
        vals.push_back(curr);

        int i = 0;
        return build(vals, i);
    }

private:
    TreeNode* build(vector<string>& vals, int& i) {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i++]));
        node->left  = build(vals, i);
        node->right = build(vals, i);

        return node;
    }
};

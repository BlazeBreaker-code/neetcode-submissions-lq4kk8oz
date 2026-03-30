class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        TrieNode* root = new TrieNode();

        for (string& s : words) {
            TrieNode* curr = root;
            for (char c : s) {
                if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
            curr->word = s;
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char c = board[i][j];
                if (root->children[c - 'a']) dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }


    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* parent, vector<string>& ans) {
        char c = board[row][col];
        TrieNode* curr = parent->children[c - 'a'];
        if (!curr) return;
        if (!curr->word.empty()) { // we found a word
            ans.push_back(curr->word);
            curr->word.clear();
        }

        board[row][col] = '#';

        if (row - 1 >= 0 && board[row - 1][col] != '#') {
            char next = board[row - 1][col];
            if (curr->children[next - 'a']) dfs(board, row - 1, col, curr, ans);
        }

        if (row + 1 < board.size() && board[row + 1][col] != '#') {
            char next = board[row + 1][col];
            if (curr->children[next - 'a']) dfs(board, row + 1, col, curr, ans);
        }

        if (col - 1 >= 0 && board[row][col - 1] != '#') {
            char next = board[row][col - 1];
            if (curr->children[next - 'a']) dfs(board, row, col - 1, curr, ans);
        }

        if (col + 1 < board[0].size() && board[row][col + 1] != '#') {
            char next = board[row][col + 1];
            if (curr->children[next - 'a']) dfs(board, row, col + 1, curr, ans);
        }

        board[row][col] = c; // backtrack

        if (isEmpty(curr)) {
            delete curr;
            parent->children[c - 'a'] = nullptr;
        }
    }

    bool isEmpty(TrieNode* node) {
        if (!node->word.empty()) return false;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) return false;
        }

        return true;
    }
};

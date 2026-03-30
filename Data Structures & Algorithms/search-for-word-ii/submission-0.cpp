class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {0};
        string word = "";
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Brute force we could've just double for looped and ran dfs for all letters
        // Optimal we can instead use a trie to check our board to search for next letter from prefix
        vector<string> ans;
        TrieNode* root = new TrieNode();
        // Set up our Trie
        for (const string& s : words) {
            TrieNode* curr = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }

                curr = curr->children[idx];
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

    private:
        void dfs(vector<vector<char>>& board, int row, int col, TrieNode* parent, vector<string>& ans) {
            char c = board[row][col];

            TrieNode* node = parent->children[c - 'a'];
            if (!node) return;
            if (!node->word.empty()) { // after we find a word add it to our answer and then clear it 
                ans.push_back(node->word);
                node->word.clear();
            }

            board[row][col] = '#'; // we've already seen this cell
            // check left, right, up and down

            if (row - 1 >= 0 && board[row - 1][col] != '#') {
                char next = board[row - 1][col];
                if (node->children[next - 'a']) dfs(board, row - 1, col, node, ans);
            }

            if (row + 1 < board.size() && board[row + 1][col] != '#') {
                char next = board[row + 1][col];
                if (node->children[next - 'a']) dfs(board, row + 1, col, node, ans);
            }

            if (col - 1 >= 0 && board[row][col - 1] != '#') {
                char next = board[row][col - 1];
                if (node->children[next - 'a']) dfs(board, row, col - 1, node, ans);
            }

            if (col + 1 < board[0].size() && board[row][col + 1] != '#') {
                char next = board[row][col + 1];
                if (node->children[next - 'a']) dfs(board, row, col + 1, node, ans);
            }

            board[row][col] = c; // backtrack
            if (isEmpty(node)) {
                delete node;
                parent->children[c - 'a'] = nullptr; // drop the ref
            }

        }

        bool isEmpty(TrieNode* node) { // used to check if the last leaf node has been found for this node
            if (!node->word.empty()) return false; // word not found yet
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) return false; // no additional children
            }

            return true;
        }
};

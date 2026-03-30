class TrieNode {
    public: 
        std::unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class WordDictionary {
    // Question -> design a structure that supports adding new words and searching for existing ones
    // basically a Trie like before -> but the key diff is that '.' can mean any character can be this value and continue
    // For this reason we need to dfs after

private:
    TrieNode* root;

    bool dfs(const string& word, int i, TrieNode* node) {
        if (i == word.size()) return node->endOfWord;
        char c = word[i];

        if (c == '.') {
            for (auto& [cha, child] : node->children) {
                if (dfs(word, i + 1, child)) return true;
            }
            return false;
        }

        if (!node->children.contains(c)) return false;
        return dfs(word, i + 1, node->children[c]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }

            curr = curr->children[c];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

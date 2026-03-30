class TrieNode {
    public: 
        std::unordered_map<char, TrieNode*> children; // <- unique character set
        bool endOfWord = false; // <- we need something to mark an end of the word node
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode(); // on the heap
    }
    
    void insert(string word) {
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
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                return false;
            }

            curr = curr->children[c];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->children.contains(c)) {
                return false;
            }

            curr = curr->children[c];
        }

        return true;
    }
};

class LRUCache {
private: 
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node (int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}; 
    };

    int cap;
    std::unordered_map<int, Node*> cache;
    Node* left;  // left boundary = least recent
    Node* right; // right boundary = most recent

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left  = new Node(0, 0);
        right = new Node(0, 0);

        left->next  = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (!cache.contains(key)) return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // we want to insert and then adjust to capacity our linked list of nodes
        // if the node already exists just move it to the top
        if (cache.contains(key)) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        while (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
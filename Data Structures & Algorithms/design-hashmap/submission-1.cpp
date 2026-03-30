class MyHashMap {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;

        ListNode (int k = -1, int v = -1) {
            key = k;
            val = v;
            next = nullptr;
        }
    };

    vector<ListNode*> order;

    ListNode* temp;

    int hash(int key) {
        return key % order.size();
    }

public:
    MyHashMap() : order(1000) {
        for (auto& bucket : order) {
            bucket = new ListNode();
        }
    }
    
    void put(int key, int value) {
        ListNode* curr = order[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) {
                curr->next->val = value;
                return;
            }

            curr = curr->next;
        }

        curr->next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode* curr = order[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) return curr->next->val;
            curr = curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = order[hash(key)];
        while (curr->next) {
            if (curr->next->key == key) { // we need to delete it from the heap
                ListNode* todelete = curr->next;
                curr->next = curr->next->next;
                delete todelete;
                return;
            }

            curr = curr->next;
        }
    }

    ~MyHashMap() {
        for (ListNode* head : order) {
            while (head) {
                ListNode* next = head->next;
                delete head;
                head = next; // repoint
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
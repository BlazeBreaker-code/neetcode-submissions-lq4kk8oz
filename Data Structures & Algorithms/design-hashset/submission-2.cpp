class MyHashSet {
private:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int v) {
            val  = v;
            next = nullptr;
        }
    };

    ListNode* temp;

public:
    MyHashSet() {
        temp = new ListNode(-1);
    }
    
    void add(int key) {
        ListNode* curr = temp;
        while (curr->next) {
            if (curr->next->val == key) return;
            curr = curr->next;
        }

        curr->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* curr = temp;
        while (curr->next) {
            if (curr->next->val == key) {
                curr->next = curr->next->next;
                return;
            }

            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        ListNode* curr = temp;
        while (curr->next) {
            if (curr->next->val == key) return true;
            curr = curr->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyHashMap {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
        }
    };

public:

    ListNode* temp;

    MyHashMap() {
        temp = new ListNode(-1, -1);    
    }
    
    void put(int key, int value) {
        ListNode* curr = temp;
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
        ListNode* curr = temp;
        while (curr->next) {
            if (curr->next->key == key) return curr->next->val;
            curr = curr->next;
        }

        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = temp;
        while (curr->next) {
            if (curr->next->key == key) {
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
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
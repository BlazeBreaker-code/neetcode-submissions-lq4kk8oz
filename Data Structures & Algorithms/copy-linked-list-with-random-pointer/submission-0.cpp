/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // deep copy a linked list with a next pointer and a random pointer
        std::unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr;

        Node* curr = head;
        while (curr) { // First create all the nodes needed in the map
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) { // Then assign them all
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};

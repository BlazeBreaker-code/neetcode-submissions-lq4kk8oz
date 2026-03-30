/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { // need to use a lambda because of the fact we are looking at pointers
            return a->val > b->val;
        };

        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* head : lists) { // push all the head nodes to the minheap
            if (head) pq.push(head);
        }

        ListNode temp(-1);
        ListNode* curr = &temp;

        while (!pq.empty()) {
            curr->next = pq.top(); pq.pop();
            curr = curr->next;
            if (curr->next) pq.push(curr->next);
        }

        curr->next = nullptr; // important to end the list
        return temp.next;

    }
};

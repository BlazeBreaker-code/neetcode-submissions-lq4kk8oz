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
private: 
    ListNode* getKth(ListNode* node, int k) {
        while (node && k-- > 0) {
            node = node->next;
        }

        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode temp(-1);
        temp.next = head;

        ListNode* prevGroup = &temp;

        while (true) {
            ListNode* kth = getKth(prevGroup, k);
            if (!kth) break;
            ListNode* nextGroup = kth->next;

            ListNode* prev = nextGroup; // this is always where you want to reverse from end value
            // would typically be nullptr here would be 4
            ListNode* curr = prevGroup->next; // this is always what you are starting with
            // would typically be head here would be 1
            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr; 
                curr = temp;
            }

            ListNode* oldhead = prevGroup->next; // 3
            prevGroup->next = kth; // 1
            prevGroup = oldhead; // for our next cycle we end at 1
        }

        return temp.next;
    }
};

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

            // Alright it's time to reverse from here
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* oldHead = prevGroup->next; // 1 
            prevGroup->next = kth;               // point to 3 instead
            prevGroup = oldHead;                 // since  1 is our end of the group that is our prev
        }

        return temp.next;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode temp(-1);
        temp.next = head;

        ListNode* beforeLeft = &temp;
        for (int i = 1; i < left; ++i) {
            beforeLeft = beforeLeft->next;
        }

        ListNode* curr = beforeLeft->next;
        ListNode* prev = nullptr;

        ListNode* tail = curr;

        for (int i = left; i <= right; ++i) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        beforeLeft->next = prev;
        tail->next = curr;

        return temp.next;
    }
};
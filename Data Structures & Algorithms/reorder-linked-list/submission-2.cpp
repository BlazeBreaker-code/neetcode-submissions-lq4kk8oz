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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;

        while (l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};

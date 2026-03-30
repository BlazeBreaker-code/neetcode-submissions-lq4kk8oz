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

        // Now we have middle and end nodes
        // We have to reverse it
        ListNode* second = slow->next;
        slow->next = nullptr; // break the end
        ListNode* prev = nullptr;

        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // Now we want to merge alternating
        ListNode* l2 = prev; // head of reversed half
        ListNode* l1 = head; // head of first half

        while (l2) {
            ListNode* n1 = l1->next;
            ListNode* n2 = l2->next;

            l1->next = l2;
            l2->next = n1;

            l1 = n1;
            l2 = n2;
        }
    }
};

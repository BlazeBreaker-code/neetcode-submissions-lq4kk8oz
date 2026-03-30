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
        // Reorder the list so the back elements intersect
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr; // we are now going to make this the end of the list
        ListNode* prev = nullptr;

        // Now we want to reverse the second part so it's 654
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // Now that it's reversed lets combine them 
        ListNode* l2 = prev; // reverse head
        ListNode* l1 = head; // head

        // 0 1 2 3   6 5 4     0 6 1 5 2 4 3 
        while (l2) {
            ListNode* next1 = l1->next; // 1 
            ListNode* next2 = l2->next; // 5

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};

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
        vector<int> nodes;

        for (ListNode* n : lists) {
            while (n) {
                nodes.push_back(n->val);
                n = n->next;
            }
        }

        std::sort(nodes.begin(), nodes.end());
        ListNode temp(-1);
        ListNode* curr = &temp;

        for (int val : nodes) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return temp.next;
    }
};

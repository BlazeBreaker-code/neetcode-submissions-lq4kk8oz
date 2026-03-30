/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
 
public class Solution 
{
    public ListNode ReverseList(ListNode head) 
    {
        // So for this question we want a previous pointer, a current pointer, and a temp pointer.
        ListNode prev = null;
        ListNode current = head;

        while (current != null)
        {
            ListNode temp = current.next;
            current.next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }
}

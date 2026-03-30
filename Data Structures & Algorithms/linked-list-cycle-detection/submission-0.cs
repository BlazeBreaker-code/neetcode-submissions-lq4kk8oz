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
    public bool HasCycle(ListNode head) 
    {
        // So for this problem if I remember it properly we need to have a forward pointer and keep going forward even further.

        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) // If there was an ending to this linked list then we would've reached it.
        {
            fast = fast.next.next;
            slow = slow.next;

            if (slow.Equals(fast))
            {
                return true;
            }
        }

        return false; // we reached an end and exited the loop.
    }
}

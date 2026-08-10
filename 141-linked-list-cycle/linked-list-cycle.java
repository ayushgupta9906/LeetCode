public class Solution {

    public boolean hasCycle(ListNode head) {

        // Slow moves 1 step, fast moves 2 steps
        ListNode slow = head;
        ListNode fast = head;

        // Check if fast can move safely
        while (fast != null && fast.next != null) {

            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution 
{
    public static ListNode Reverse(ListNode head)
    {
        ListNode temp=head;
        ListNode prev=null;
        while(temp != null)
        {
            ListNode nn=temp.next;
            temp.next=prev;
            prev=temp;
            temp=nn;
        }
        return prev;
    }
    public int[] nextLargerNodes(ListNode head) 
    {
        Stack<Integer> st=new Stack<>();
        head=Reverse(head);
        ListNode temp=head;
        int cnt=0;
        while(temp != null)
        {
            cnt++;
            temp=temp.next;
        }
        int[] res=new int[cnt];
        int i=cnt-1;
        while(head != null)
        {
            while(!st.isEmpty() && st.peek() <= head.val )
            {
                st.pop();
            }
            res[i--]=st.isEmpty()?0:st.peek();
            st.push(head.val);
            head=head.next;
        }
        return res;
    }
}
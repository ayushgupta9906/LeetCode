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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode *tmp = new ListNode(head->val, head);
        ListNode *pre = tmp;
        ListNode *cur = head;
        while(cur != nullptr)
        {
            if (pre->val <= cur->val)
            {
                pre = cur;
                cur = cur->next;
                continue;
            }
            
            ListNode *p = tmp;
            while(p->next->val <= cur->val)
            {
                p = p->next;
            }
            
            ListNode *t = cur->next;
            cur->next = p->next;
            p->next = cur;
            pre->next = t;
            cur = t;
        }
        return tmp->next;
    }
};
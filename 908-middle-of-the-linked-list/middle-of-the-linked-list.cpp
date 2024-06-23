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
    //To calculate the length.
    int calculatelen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int len=calculatelen(head);
        int count=0, half;
        if(len%2==0) half=len/2;
        else half=(len/2)+1;
        ListNode* temp=head;
        while(count!=half){
            temp=temp->next;
            count++;
        }
        return temp;
    }
};
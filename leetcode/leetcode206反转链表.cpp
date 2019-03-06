/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *u = head;
        if(head == NULL || head->next == NULL)
            return head;
        p = p->next;
        q = p;
        u->next = NULL;
        
        while(p!=NULL)
        {
            p=p->next;
            q->next = u;
            u = q;
            q = p;
        }
        return u;
    }
};